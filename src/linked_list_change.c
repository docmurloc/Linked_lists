/*
** EPITECH PROJECT, 2019
** function_utile
** File description:
** chain_list_change
*/

#include "linked_list.h"

void change_value(node_t *obj, void *ptr_value, type_t type)
{
    if (obj == NULL || ptr_value == NULL)
        return;
    switch (type)
    {
    case (type_int):
        obj->_data._int = *((int *)(ptr_value));
        break;
    case (type_float):
        obj->_data._float = *((float *)(ptr_value));
        break;
    case (type_char):
        obj->_data._char = *((char *)(ptr_value));
        break;
    default:    
        obj->_data._pointer = *((void **)(ptr_value));
        break;
    }
    obj->_type = type;
}

void change_value_rank(head_node_t *obj, void *ptr, type_t type, int rank)
{
    node_t *buffer = get_node(obj, rank);

    if (obj == NULL || ptr == NULL || buffer == NULL)
        return;
    change_value(buffer, ptr, type);
}