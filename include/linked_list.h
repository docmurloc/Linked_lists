/*
** EPITECH PROJECT, 2019
** function_utile
** File description:
** chaine_list
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//#define STOCK_LIST

typedef union linked_list_type_s
{
    float _float;
    int _int;
    char _char;
    void *_pointer;
} linked_list_type_t;

void stock_int(linked_list_type_t *box, void *ptr_value);
void stock_float(linked_list_type_t *box, void *ptr_value);
void stock_char(linked_list_type_t *box, void *ptr_value);
void stock_void_ptr(linked_list_type_t *box, void *ptr_value);

typedef enum type_s
{
    type_int,
    type_float,
    type_char,
    type_pointer,
    type_array,
    type_unknown
} type_t;

typedef struct node_s
{
    struct node_s *_next;
    struct node_s *_before;
    linked_list_type_t _data;
    type_t _type;
} node_t;

node_t *create_node(void);
node_t *create_node_data(void *ptr_data, type_t type);
void delete_node(node_t *obj);
void init_node(node_t *obj);
void connect_node(node_t *before, node_t *after);
void isole_node(node_t *obj);

typedef struct head_node_s
{
    int _nb_node;
    node_t *_head;
} head_node_t;

void init_linked_list(head_node_t *obj);

void add_element_back(head_node_t *obj, node_t *element);
void add_element_front(head_node_t *obj, node_t *element);
void add_element_rank(head_node_t *obj, node_t *elemnt, int rank);
void add_data(head_node_t *obj, void *ptr_data, type_t type);
void add_data_rank(head_node_t *obj, void *ptr_data, type_t type, int rank);
void first_node(head_node_t *obj, node_t *element);

int is_element(node_t *obj, void *ptr_cmp, type_t type);
int get_rank_element(head_node_t *obj, void *ptr_cmp, type_t type);
node_t *get_node(head_node_t *obj, int rank);
linked_list_type_t *get_data(head_node_t *obj, int rank);

void delete_node(node_t *obj);
void delete_node_rank(head_node_t *obj, int rank);
void clear_link(head_node_t *obj);
void delete_link(head_node_t *obj);

void change_value(node_t *obj, void *ptr_value, type_t type);
void change_value_rank(head_node_t *obj, void *ptr, type_t type, int rank);

#endif
