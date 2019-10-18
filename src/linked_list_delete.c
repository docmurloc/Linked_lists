/*
** EPITECH PROJECT, 2019
** function_utile
** File description:
** chain_list_delete
*/

#include "linked_list.h"

void delete_node(node_t *obj)
{
    if (obj == NULL)
        return;
    isole_node(obj);
    free(obj);
}

void delete_node_rank(head_node_t *obj, int rank)
{
    node_t *buffer = get_node(obj, rank);

    if (obj == NULL || buffer == NULL)
        return;
    if (buffer == obj->_head) {
        obj->_head = obj->_head->_next;
        if (obj->_nb_node <= 1)
            obj->_head = NULL;
    }
    delete_node(buffer);
    obj->_nb_node -= 1;
}

void clear_chaine(head_node_t *obj)
{
    if (obj == NULL)
        return;
    while (obj->_head != NULL)
        delete_node_rank(obj, 0);
}

void delete_chaine(head_node_t *obj)
{
    if (obj == NULL)
        return;
    clear_chaine(obj);
    free(obj);
}
