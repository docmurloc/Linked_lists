/*
** EPITECH PROJECT, 2019
** function_utile
** File description:
** chaine_list_look_for
*/

#include "linked_list.h"

static int is_int(node_t *obj, void *ptr_cmp)
{
    if (obj == NULL || ptr_cmp == NULL)
        return (0);
    if (*((int *)ptr_cmp) == obj->_data._int)
        return (1);
    return (0);
}

static int is_float(node_t *obj, void *ptr_cmp)
{
    if (obj == NULL || ptr_cmp == NULL)
        return (0);
    if (*((float *)ptr_cmp) == obj->_data._float)
        return (1);
    return (0);
}

static int is_char(node_t *obj, void *ptr_cmp)
{
    if (obj == NULL || ptr_cmp == NULL)
        return (0);
    if (*((char *)ptr_cmp) == obj->_data._char)
        return (1);
    return (0);
}

static int is_ptr(node_t *obj, void *ptr_cmp)
{
    if (*((void **)ptr_cmp) == obj->_data._pointer) {
        return (1);
    } else if (obj->_type == type_array) {
        if (strcmp(*((void **)(ptr_cmp)), obj->_data._pointer) == 0) {
            return (1);
        }
    }
    return (0);
}

int is_element(node_t *obj, void *ptr_cmp, type_t type)
{
    if (obj == NULL || ptr_cmp == NULL)
        return (0);
    switch (type)
    {
    case (type_int):
        return (is_int(obj, ptr_cmp));
        break;
    case (type_float):
        return (is_float(obj, ptr_cmp));
        break;
    case (type_char):
        return (is_char(obj, ptr_cmp));
        break;
    default:
        return (is_ptr(obj, ptr_cmp));
        break;
    }
}