/*
** EPITECH PROJECT, 2019
** function_utile
** File description:
** chaine_list_add_data
*/

#include "linked_list.h"

void add_data(head_node_t *obj, void *ptr_data, type_t type)
{
    node_t *new = NULL;

    if (obj == NULL || ptr_data == NULL)
        return;
    new = create_node_data(ptr_data, type);
    add_element_back(obj, new);
}

void add_data_rank(head_node_t *obj, void *ptr_data, type_t type, int rank)
{
    node_t *new = NULL;

    if (obj == NULL || ptr_data == NULL)
        return;
    new = create_node_data(ptr_data, type);
    add_element_rank(obj, new, rank);
}