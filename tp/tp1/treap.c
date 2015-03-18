#include <stdlib.h>
#include "treap.h"

struct node *root = NULL;

void insert_node(int value, struct node **tree) {
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
};

int search_node(int value, struct node *tree) {
    if(tree == NULL) {
        return -1;
    } else if(tree->value == value) {
        return value;
    } else if(value > tree->value) {
        return search_node(value, tree->right);
    } else if(value < tree->value) {
        return search_node(value, tree->left);
    }
};

void remove_node(int value, struct node **tree);