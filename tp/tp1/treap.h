struct node {
    int priority;
    int value;
    int size;
    struct node *left;
    struct node *right;
};

struct node *root;

void insert_node(int value, struct node **tree);

struct node* search_node(int value, struct node **tree, char * path, int size_of_path);

void remove_node(int value, struct node **tree);

struct node* split_tree(int value, struct node **tree);