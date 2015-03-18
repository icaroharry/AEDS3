struct node {
    int priority;
    int value;
    struct node *left;
    struct node *right;
};

struct node *root;

void insert_node(int value, struct node **tree);

int search_node(int value, struct node *tree);

void remove_node(int value, struct node **tree);

//void split_tree(int value, struct node **tree);