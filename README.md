# Linked_lists
double linked lists that can take multiple types

this project is a linked list that have the  avantage to take more than one type in it.

you can see how to use it in the ./test_unit/test.c file.

If you want to use it as it you only need to know these function:

- void init_linked_list(head_node_t *obj)

- void add_data(head_node_t *obj, void *ptr_data, type_t type)
- void add_data_rank(head_node_t *obj, void *ptr_data, type_t type, int rank)

- int get_rank_element(head_node_t *obj, void *ptr_cmp, type_t type)

// you get a reference to the linked_list_type_t in the node of the linked list
- linked_list_type_t *get_data(head_node_t *obj, int rank)

// use clear_link if you did not malloc your head_node_t and delete_link otherwise
- void clear_link(head_node_t *obj)
- void delete_link(head_node_t *obj)

- void change_value_rank(head_node_t *obj, void *ptr, type_t type, int rank);

'ptr_cmp' is a pointer to the value you want to put in your liste and 'type' is a enum to know how the linked liste should treat this data.

for exemple: 
---------------------------
int data = 1;
void *pointer = malloc(sizeof(int));
head_node_t obj;

init_linked_list(&obj);

// it will copy the data and will not get the reference
add_data(&obj, &data, type_int);
add_data(&obj, &pointer, type_pointer);

----------------------------

'rank' can be negative(right to left) or more than the number of node in the linked list. 
