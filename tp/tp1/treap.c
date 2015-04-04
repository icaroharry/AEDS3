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
        if(temp->size) {
            temp->size++;
        } else {
            temp->size = 0;
        }
        *tree = temp;
    } else if(value > (*tree)->value) {
        insert_node(value, &(*tree)->right);
    } else if(value < (*tree)->value) {
        insert_node(value, &(*tree)->left);
    }
}

/**
 * Function that searches a value in the tree.
 * 
 * @param  int value           - Value searched
 * @param  struct node **tree  - Pointer to the tree to look up
 * @param  char * path         - Path to the node (L for Left and R for Right)
 * @param  int size_of_path    - Each way taken in the tree, increments the size of path
 * @return struct node *tree   - Node founded or NULL if not found.         
 */
struct node* search_node(int value, struct node **tree, char * path, int size_of_path) {
    printf("%s\n",path );
    if((*tree) == NULL) {
        return NULL;
    } else if((*tree)->value == value) {
        return (*tree);
    } else if(value > (*tree)->value) {
        path[size_of_path] = 'R';
        size_of_path++;
        return search_node(value, &(*tree)->right, path, size_of_path);
    } else if(value < (*tree)->value) {
        path[size_of_path] = 'L';
        size_of_path++;
        return search_node(value, &(*tree)->left, path, size_of_path);
    }
}

void remove_node(int value, struct node **tree);

struct node* split_tree(int value, struct node **tree) {
    
}