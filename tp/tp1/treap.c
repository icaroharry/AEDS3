#include <stdlib.h>
#include <stdio.h>
#include "treap.h"

struct node *root = NULL;

void insert_node(int value, struct node **tree) {
    /** TODO: discover if there's an way to free this pointer */
    struct node *temp = NULL;
    if(*tree == NULL) {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->left = NULL;
        temp->right = NULL;
        temp->value = value;
        printf("%d\n", value);
        *tree = temp;
    } else if(value > (*tree)->value) {
        printf("right\n");
        insert_node(value, &(*tree)->right);
    } else if(value < (*tree)->value) {
        printf("left\n");        
        insert_node(value, &(*tree)->left);
    }
}

/**
 * This function searches for the position to insert a new node
 * @param  int value           - Value searched
 * @param  struct node **tree  - Pointer to the tree to look up
 * @return struct node *tree   - Tree that contains the value searched or the last value searched
 */
struct node* search_node(int value, struct node **tree) {
    /** This will return the node either the value was founded or it doesn't exist */
    if( ((*tree)->left == NULL && (*tree)->right == NULL) || ((*tree)->right->value == value || (*tree)->left->value == value) || ((*tree)->value == value)) {
        return *tree;
    } else if(value > (*tree)->value) {
        if((*tree)->right->value == NULL) {
            return *tree;
        } else {
            return search_node(value, &(*tree)->right);
        }
    } else if(value < (*tree)->value) {
        if((*tree)->left->value == NULL) {
            return *tree;
        } else {
            return search_node(value, &(*tree)->left);
        }
    }
}

void remove_node(int value, struct node **tree);

struct node* split_tree(int value, struct node **tree) {
    struct node *a, *b, *search;
    a = *tree;
    search = search_node(value, &a);
    if(search->right == NULL && search->left == NULL) {
        return NULL;
    } else if(search->right->value == value) {
        b = search->right;
        search->right == null;
        return b;
    } else if(search->left->value == value) {
        b = search->left;
        search->left == null;
        return b;
    }
}