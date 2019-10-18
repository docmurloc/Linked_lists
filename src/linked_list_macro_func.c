/*
** EPITECH PROJECT, 2019
** function_utile
** File description:
** chaine_list_macro_func
*/

#include "linked_list.h"

void stock_int(linked_list_type_t *box, void *ptr_value)
{
    box->_int = *((int *)(ptr_value));
}

void stock_float(linked_list_type_t *box, void *ptr_value)
{
    box->_float = *((float *)(ptr_value));
}

void stock_char(linked_list_type_t *box, void *ptr_value)
{
    box->_char = *((char *)(ptr_value));
}

void stock_void_ptr(linked_list_type_t *box, void *ptr_value)
{
    box->_pointer = *((void **)(ptr_value));
}