/*
** EPITECH PROJECT, 2019
** function_utile
** File description:
** chaine_list_add
*/

#include "linked_list.h"

void first_node(head_node_t *obj, node_t *elemnt)
{
    if (obj == NULL || elemnt == NULL)
        return;
    obj->_head = elemnt;
    obj->_nb_node += 1;
}

void add_element_back(head_node_t *obj, node_t *elemnt)
{
    if (obj == NULL || elemnt == NULL)
        return;
    if (obj->_head == NULL) {
        first_node(obj, elemnt);
    } else {
        connect_node(obj->_head->_before, elemnt);
        connect_node(elemnt, obj->_head);
        obj->_nb_node += 1;
    }
}

void add_element_front(head_node_t *obj, node_t *elemnt)
{
    if (obj == NULL || elemnt == NULL)
        return;
    if (obj->_head == NULL) {
        first_node(obj, elemnt);
    } else {
        connect_node(elemnt, obj->_head->_next);
        connect_node(obj->_head, elemnt);
        obj->_nb_node += 1;
    }
}

static void sub_add_element_rank(head_node_t *obj, node_t *elemnt, int rank)
{
    node_t *buffer = NULL;

    if (rank == 0) {
        add_element_back(obj, elemnt);
        obj->_head = elemnt;
    } else {
        buffer = get_node(obj, rank);
        if (buffer == NULL)
            return;
        connect_node(buffer->_before, elemnt);
        connect_node(elemnt, buffer);
        obj->_nb_node += 1;
    }
}

void add_element_rank(head_node_t *obj, node_t *elemnt, int rank)
{
    if (obj == NULL || elemnt == NULL)
        return;
    if (obj->_head == NULL) {
        first_node(obj, elemnt);
    } else {
        sub_add_element_rank(obj, elemnt, rank);
    }
}