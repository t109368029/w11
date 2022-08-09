typedef struct num_storage
{
    int number;
    struct num_storage *next;
    struct num_storage *prev;
    
} tNumStorage;

typedef struct num_stor_head
{
    int counts;
    struct num_storage *head;
    struct num_storage *tail;
} tNumStorHead;

void initial_list(tNumStorHead *list);

void print_list(tNumStorHead *list);

void sort_list(tNumStorHead *list, int input , int target_node, int before_after);
void delete_node(tNumStorHead *list, int target_node);