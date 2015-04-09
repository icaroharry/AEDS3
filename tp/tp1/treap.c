#include <stdlib.h>
#include <stdio.h>
#include "treap.h"

/**
 * Function that searches a value in the treap.
 *
 * @complexity O(log n) [O(n) in worst case]
 * 
 * @param  int value           - Value searched
 * @param  struct node **treap  - Pointer to the treap to look up
 * @return struct node *treap   - Node founded or NULL if not found.         
 */
struct node* search_node(int value, struct node **treap) {
    if((*treap) == NULL) {
        return NULL;
    } else if((*treap)->value == value) {
        return (*treap);
    } else if(value > (*treap)->value) {
        return search_node(value, &(*treap)->right);
    } else if(value < (*treap)->value) {
        return search_node(value, &(*treap)->left);
    }
    return NULL;
}


/**
 * Function that "walks" through the treap, printing the path 
 *
 * @complexity O(log n) [O(n) in worst case]
 * 
 * @param  int value            - Value searched
 * @param  struct node **treap  - Pointer to the treap to look up
 */
void print_path(int value, struct node **treap) {
    if((*treap)->value == value) {
        return;
    } else if(value > (*treap)->value) {
        printf("R");
        print_path(value, &(*treap)->right);
    } else if(value < (*treap)->value) {
        printf("L");
        print_path(value, &(*treap)->left);
    }
    return;
}

/**
 * Searches for the value and print the path if found, or -1 if not.
 *
 * @complexity O(log n) [2 * O(n) in worst case]
 * 
 * @param value [description]
 * @param treap [description]
 */
void locate_node(int value, struct node **treap) {
    struct node* found = search_node(value, &(*treap));
    if(found != NULL) {
        print_path(value, &(*treap));
        printf("\n");
    } else {
        printf("-1\n");
    }
}

/**
 * Function that swap the pointers to treaps
 * 
 * @param struct node **a
 * @param struct node **b
 */
void swap(struct node **a, struct node **b) {
    struct node *aux;
    aux = (*a);
    (*a) = (*b);
    (*b) = aux;
}

/**
 * Splits a given treap in two other treaps, one containing all the nodes with value
 * less or equal the given value, and the other containing all the nodes with value
 * greater than the given value
 *
 * @complexity O(log n) [O(n) in worst case]
 * 
 * @param int value            - Given value
 * @param struct node **treap  - Treap to be splited
 * @param struct node **left   - Treap that will contain all the minor values
 * @param struct node **right  - Treap that will contain all the greater values
 */
void split_treap(int value, struct node **treap, struct node **left, struct node **right) {
    if((*treap) != NULL) {
        if((*treap)->value == value) {
            (*left) = (*treap);
            (*right) = (*treap)->right;      
            (*left)->right = NULL;
        } else if(value > (*treap)->value) {
            (*left) = (*treap);
            split_treap(value, &(*treap)->right, &(*left)->right, &(*right));
        } else if(value < (*treap)->value) {
            (*right) = (*treap);
            split_treap(value, &(*treap)->left, &(*left), &(*right)->left);
        }
    } else {
        (*left) = NULL;
        (*right) = NULL;
    }
}

/**
 * Given two treaps, that function merge them in the first one.
 *
 * @complexity O(log n) [O(n) in worst case]
 * 
 * @param struct node **a       
 * @param struct node **b         
 * @param char direction  - Char that contains which direction the algorithm should take
 */
void merge_treaps(struct node **a, struct node **b, char direction) {
    if((*a) != NULL && (*b) != NULL) {
        if ((*a)->priority > (*b)->priority){
            swap(&(*a), &(*b));
            merge_treaps(&(*a), &(*b), 'L');
        } else {
            /**
             * We've to look only to the internal extremities in the treap
             * that's why we look or to the lef or to the right
             */
            switch (direction) {
                case 'L':
                    if((*a)->left == NULL) {
                        (*a)->left = (*b);
                    } else if((*a)->left->priority > (*b)->priority) {
                        swap(&(*a)->left, &(*b));
                        merge_treaps(&(*a)->left, &(*b), 'R');
                    } else {
                        merge_treaps(&(*a)->left, &(*b), 'L');
                    }
                    break;
                case 'R':
                    if((*a)->right == NULL) {
                        (*a)->right = (*b);
                    } else if((*a)->right->priority > (*b)->priority) {
                        swap(&(*a)->right, &(*b));
                        merge_treaps(&(*a)->right, &(*b), 'L');
                    } else {
                        merge_treaps(&(*a)->right, &(*b), 'R');
                    }
                    break;
            }
        }
    } else {
        if((*a) == NULL) {
            swap(&(*a), &(*b));
        }
    }
}

/**
 * Given a value and a priority, this function creates a new node and
 * inserts it into the given treap.
 * To do that, we perform a split in the treap, using the given value,
 * then we merge the created node with the two splited parts of the
 * given treap.
 *
 * @complexity O(log n) [O(n) in worst case]
 *  
 * @param int value              - Value of the new node
 * @param int priority           - Priority of the new node
 * @param struct node **treap    - Pointer to treap to insert the new node
 */
void insert_node(int value, int priority, struct node **treap) {
    /** Auxilary pointers to divide the treap */
    struct node *aux_left = NULL, *aux_right = NULL;
    
    /** New node */
    struct node *node_to_insert = (struct node *)malloc(sizeof(struct node));

    node_to_insert->value = value;
    node_to_insert->priority = priority;

    split_treap(node_to_insert->value, &(*treap), &aux_left, &aux_right);
    merge_treaps(&aux_left, &node_to_insert, 'R');
    merge_treaps(&aux_left, &aux_right, 'R');
    (*treap) = aux_left;
}

/**
 * Remove the node with the given value from the given treap.
 * To do that we split the treap in 3 parts: the first containing
 * all the values minors than the given value. The second containing
 * only the node to remove, and the third containing all the values greater
 * than the given value.
 *
 * @complexity O(log n) [O(n) in worst case]
 * 
 * @param int value            - Value of the node to remove
 * @param struct node **treap  - Pointer to the treap that contains the value
 */
void remove_node(int value, struct node **treap) {
    /** Auxilary pointers to divide the treap */
    struct node *a = NULL, *b = NULL, *c = NULL, *d = NULL;
    
    split_treap((value - 1), &(*treap), &a, &b);
    split_treap((value), &b, &c, &d);
    merge_treaps(&a, &d, 'R');
    
    (*treap) = a;
    if(c != NULL) {
        free(c);
    }
}

/**
 * Print the value and priority of each node
 *
 * @complexity O(n)
 * 
 * @param struct node *treap - Treap to print
 */
void print_treap(struct node *treap) {
    if((treap) != NULL) {
        printf("%d:%d ", treap->value, treap->priority);
        print_treap(treap->left);
        print_treap(treap->right);
    }
}

/**
 * Destroy each node of the given treap.
 *
 * @complexity O(n)
 * 
 * @param struct node *treap - Treap to destroy
 */
void destroy_treap(struct node *treap) {
    if((treap) != NULL) {
        destroy_treap(treap->left);
        destroy_treap(treap->right);
        free(treap);
    }
}

/**
 * Auxiliary function (not used in the main program), that
 * verifies if the given treap is valid.
 *
 * @complexity O(n)
 * 
 * @param struct node *treap - Treap to verify
 */
void verify_treap(struct node *treap) {
    if(treap != NULL) {
        if(treap->right != NULL) {
            if(treap->value < treap->right->value && treap->priority < treap->right->priority) {
                verify_treap(treap->right);
            } else {
                printf("INVALID TREAP AT NODE: %d:%d\n", treap->value, treap->priority);
            }
        } 
        if(treap->left != NULL) {
            if(treap->value > treap->left->value && treap->priority < treap->left->priority) {
                verify_treap(treap->left);
            } else {
                printf("INVALID TREAP AT NODE: %d:%d\n", treap->value, treap->priority);
            }
        }
    } else {
        printf("NULL TREAP\n");
    }
}