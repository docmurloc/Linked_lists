/*
** EPITECH PROJECT, 2019
** function_utile
** File description:
** chaine_list_init
*/

#include "linked_list.h"

void init_node(node_t *obj)
{
    if (obj == NULL)
        return;
    memset(obj, 0, sizeof(node_t));
    obj->_next = obj;
    obj->_before = obj;
    obj->_type = type_unknown;
}

void init_chaine_list(head_node_t *obj)
{
    if (obj == NULL)
        return;
    memset(obj, 0, sizeof(head_node_t));
}