/*
** EPITECH PROJECT, 2019
** function_utile
** File description:
** chaine_list_get
*/

#include "linked_list.h"

static node_t *get_node_rotate_left(head_node_t *obj, int rank)
{
    node_t *result = obj->_head;
    int limit = rank % obj->_nb_node;

    for (int i = 0; i > limit; i--) {
        if (result->_before == NULL)
            return (NULL);
        result = result->_before;
    }
    return (result);
}

static node_t *get_node_rotate_right(head_node_t *obj, int rank)
{
    node_t *result = obj->_head;
    int limit = rank % obj->_nb_node;

    for (int i = 0; i < limit; i++) {
        if (result->_next == NULL)
            return (NULL);
        result = result->_next;
    }
    return (result);
}

node_t *get_node(head_node_t *obj, int rank)
{
    node_t *result = NULL;

    if (obj == NULL || obj->_head == NULL || obj->_nb_node == 0)
        return (NULL);
    if (rank < 0)
        result = get_node_rotate_left(obj, rank);
    else
        result = get_node_rotate_right(obj, rank);
    return (result);
}

linked_list_type_t *get_data(head_node_t *obj, int rank)
{
    node_t *result = NULL;

    if (obj == NULL || obj->_head == NULL || obj->_nb_node == 0)
        return (NULL);
    result = get_node(obj, rank);
    if (result == NULL)
        return (NULL);
    return (&(result->_data));
}