/*
** EPITECH PROJECT, 2019
** function_utile
** File description:
** chaine_list_create
*/

#include "linked_list.h"

node_t *create_node(void)
{
    node_t *result = malloc(sizeof(node_t));

    if (result == NULL) {
        printf("malloc failed\n");
        exit(84);
    }
    init_node(result);
    return (result);
}

node_t *create_node_data(void *ptr_data, type_t type)
{
    node_t *result = create_node();

    result->_type = type;
    switch (type)
    {
    case (type_int):
        result->_data._int = *((int *)(ptr_data));
        break;
    case (type_float):
        result->_data._float = *((float *)(ptr_data));
        break;
    case (type_char):
        result->_data._char = *((char *)(ptr_data));
        break;
    default:
        result->_data._pointer = *((void **)(ptr_data));
        break;
    }
    return (result);
}