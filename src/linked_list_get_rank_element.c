/*
** EPITECH PROJECT, 2019
** function_utile
** File description:
** chaine_list_get_rank_element
*/

#include "linked_list.h"

int get_rank_element(head_node_t *obj, void *ptr_cmp, type_t type)
{
    node_t *buffer = get_node(obj, 0);

    if (obj == NULL || ptr_cmp == NULL || buffer == NULL)
        return (-1);
    for (int i = 0; i < obj->_nb_node; i++) {
        buffer = get_node(obj, i);
        if (is_element(buffer, ptr_cmp, type))
            return (i);
    }
    return (-1);
}