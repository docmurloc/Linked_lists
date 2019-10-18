/*
** EPITECH PROJECT, 2019
** function_utile
** File description:
** chaine_list_connect
*/

#include "linked_list.h"

void connect_node(node_t *before, node_t *after)
{
    if (before == NULL || after == NULL)
        return;
    before->_next = after;
    after->_before = before;
}

void isole_node(node_t *obj)
{
    if (obj == NULL)
        return;
    if (obj->_before != NULL)
        obj->_before->_next = NULL;
    if (obj->_next != NULL)
        obj->_next->_before = NULL;
    connect_node(obj->_before, obj->_next);
    connect_node(obj, obj);
}