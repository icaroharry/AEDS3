#include <stdio.h>
#include <string.h>
#include "treap.h"

#define ins "INSERT"
#define rem "REMOVE"
#define loc "LOCATE"

int main() {
    int n, i, priority, value;
    char action[8], action_tok[8];
    struct node *treap;
    treap = NULL;

    scanf("%d\n", &n);
    for(i = 0; i < n; i++) {
        scanf("%6s ", action_tok);
        strncpy(action, action_tok, 6);
        action[7] = '\0';
        if(strcmp(action, ins) == 0) {
            if(scanf("%d %d", &value, &priority) == 2) { 
                insert_node(value, priority, &treap);                   
            }
        } else if(strcmp(action, rem) == 0) {
            if(scanf("%d", &value) == 1) {
                remove_node(value, &treap);
            }
        } else if(strcmp(action, loc) == 0) {
            if(scanf("%d", &value) == 1) {
                locate_node(value, &treap);
            }
        }
    }

    destroy_treap(treap);
    return 0;
}