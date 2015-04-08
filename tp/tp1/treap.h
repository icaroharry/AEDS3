struct node {
    int priority;
    int value;
    int size;
    struct node *left;
    struct node *right;
};

struct node* search_node(int value, struct node **treap);

void locate_node(int value, struct node **treap);

void print_path(int value, struct node **treap);

void split_treap(int value, struct node **treap, struct node **left, struct node **right);

void swap(struct node **a, struct node **b);

void merge_treaps(struct node **a, struct node **b, char direction);

void insert_node(int value, int priority, struct node **treap);

void remove_node(int value, struct node **treap);

void print_treap(struct node *treap);

void destroy_treap(struct node *treap);

void verify_treap(struct node *treap);