struct node {
    int priority;
    int value;
    struct node *left;
    struct node *right;
};

struct node *root;

void insert_node(int value, struct node **tree);

struct node* search_node(int value, struct node **tree);

void remove_node(int value, struct node **tree);

struct node* split_tree(int value, struct node **tree);