/*
** EPITECH PROJECT, 2019
** function_utile
** File description:
** test
*/

#include <criterion/criterion.h>
#include "linked_list.h"

Test(linked_list_init, node_init)
{
    node_t node;
    init_node(&node);
    cr_assert(node._data._int == 0, "The result was %d. Expected %d", node._data._int, 0);
    cr_assert(node._next == &node, "The result was %p. Expected %p", node._next, &node);
    cr_assert(node._before == &node, "The result was %p. Expected %p", node._before, &node);
}
Test(linked_list_init, linked_list_init)
{
    head_node_t head;
    init_linked_list(&head);
    cr_assert(head._head == NULL, "The result was %p. Expected %p", head._head, NULL);
    cr_assert(head._nb_node == 0, "The result was %d. Expected %d", head._nb_node, 0);
}

Test(linked_list_connect, node_connect)
{
    node_t *a = malloc(sizeof(node_t));
    node_t *b = malloc(sizeof(node_t));

    init_node(a);
    init_node(b);
    connect_node(a, b);
    cr_assert(a->_next == b, "The result was %p. Expected %p", a->_next, b);
    cr_assert(b->_before == a, "The result was %p. Expected %p", b->_before, a);

    free(a);
    free(b);
}

Test(linked_list_init, node_isole)
{
    node_t a;
    node_t b;
    node_t c;

    init_node(&a);
    init_node(&b);
    init_node(&c);
    connect_node(&a, &b);
    connect_node(&b, &c);
    cr_assert(a._next == &b, "The result was %p. Expected %p", a._next, &b);
    cr_assert(a._before == &a, "The result was %p. Expected %p", a._before, &a);
    cr_assert(b._next == &c, "The result was %p. Expected %p", b._next, &c);
    cr_assert(b._before == &a, "The result was %p. Expected %p", b._before, &a);
    cr_assert(c._next == &c, "The result was %p. Expected %p", c._next, &c);
    cr_assert(c._before == &b, "The result was %p. Expected %p", c._before, &b);
    isole_node(&b);
    cr_assert(a._next == &c, "The result was %p. Expected %p", a._next, &c);
    cr_assert(a._before == &a, "The result was %p. Expected %p", a._before, &a);
    cr_assert(b._next == &b, "The result was %p. Expected %p", b._next, &b);
    cr_assert(b._before == &b, "The result was %p. Expected %p", b._before, &b);
    cr_assert(c._next == &c, "The result was %p. Expected %p", c._next, &c);
    cr_assert(c._before == &a, "The result was %p. Expected %p", c._before, &a);
}

Test(linked_list_create, node_create_data)
{
    int _int = 4;
    char _char = 10;
    float _float = 20.5;
    int *_pointer = &_int;

    node_t *node_int = create_node_data(&_int, type_int);
    node_t *node_char = create_node_data(&_char, type_char);
    node_t *node_float = create_node_data(&_float, type_float);
    node_t *node_pointer = create_node_data(&_pointer, type_pointer);

    cr_assert(node_int->_data._int == 4, "The result was %d. Expected %d", node_int->_data._int, 4);
    cr_assert(node_char->_data._char == 10, "The result was %c. Expected %c", node_char->_data._char, 10);
    cr_assert(node_float->_data._float == 20.5, "The result was %f. Expected %f", node_float->_data._float, 20.5);
    cr_assert(node_pointer->_data._pointer == _pointer, "The result was %p. Expected %p", node_pointer->_data._pointer, _pointer);

    free(node_char);
    free(node_int);
    free(node_float);
    free(node_pointer);
}

Test(linked_list_add, node_first)
{
    head_node_t head;
    node_t node;

    init_linked_list(&head);
    init_node(&node);

    first_node(&head, &node);
    cr_assert(head._nb_node == 1, "The result was %d. Expected %d", head._nb_node, 1);
    cr_assert(head._head == &node, "The result was %p. Expected %p", head._head, &node);
}

Test(linked_list_add, add_element_back_)
{
    head_node_t head;
    node_t a;
    node_t b;
    node_t c;

    init_linked_list(&head);
    init_node(&a);
    init_node(&b);
    init_node(&c);

    add_element_back(&head, &a);
    cr_assert(head._nb_node == 1, "The result was %d. Expected %d", head._nb_node, 1);
    cr_assert(head._head == &a, "The result was %p. Expected %p", head._head, &a);
    add_element_back(&head, &b);
    cr_assert(head._head == &a, "The result was %p. Expected %p", head._head, &a);
    cr_assert(head._nb_node == 2, "The result was %d. Expected %d", head._nb_node, 1);
    cr_assert(head._head->_before == &b, "The result was %p. Expected %p", head._head->_before, &b);
    cr_assert(head._head->_next == &b, "The result was %p. Expected %p", head._head->_next, &b);
    cr_assert(b._next == &a, "The result was %p. Expected %p", b._next, &a);
    cr_assert(b._before == &a, "The result was %p. Expected %p", b._before, &a);

    add_element_back(&head, &c);
    cr_assert(head._nb_node == 3, "The result was %d. Expected %d", head._nb_node, 1);
    cr_assert(head._head == &a, "The result was %p. Expected %p", head._head, &a);
    cr_assert(head._head->_before == &c, "The result was %p. Expected %p", head._head->_before, &c);
    cr_assert(head._head->_next == &b, "The result was %p. Expected %p", head._head->_next, &b);
    cr_assert(b._next == &c, "The result was %p. Expected %p", b._next, &c);
    cr_assert(b._before == &a, "The result was %p. Expected %p", b._before, &a);
    cr_assert(c._next == &a, "The result was %p. Expected %p", c._next, &a);
    cr_assert(c._before == &b, "The result was %p. Expected %p", c._before, &b);

}

Test(linked_list_add, add_element_front_)
{
    head_node_t head;
    node_t a;
    node_t b;
    node_t c;

    init_linked_list(&head);
    init_node(&a);
    init_node(&b);
    init_node(&c);

    add_element_front(&head, &a);
    cr_assert(head._nb_node == 1, "The result was %d. Expected %d", head._nb_node, 1);
    cr_assert(head._head == &a, "The result was %p. Expected %p", head._head, &a);
    add_element_front(&head, &b);
    cr_assert(head._head == &a, "The result was %p. Expected %p", head._head, &a);
    cr_assert(head._nb_node == 2, "The result was %d. Expected %d", head._nb_node, 1);
    cr_assert(head._head->_before == &b, "The result was %p. Expected %p", head._head->_before, &b);
    cr_assert(head._head->_next == &b, "The result was %p. Expected %p", head._head->_next, &b);
    cr_assert(b._next == &a, "The result was %p. Expected %p", b._next, &a);
    cr_assert(b._before == &a, "The result was %p. Expected %p", b._before, &a);

    add_element_front(&head, &c);
    cr_assert(head._nb_node == 3, "The result was %d. Expected %d", head._nb_node, 1);
    cr_assert(head._head == &a, "The result was %p. Expected %p", head._head, &a);
    cr_assert(head._head->_before == &b, "The result was %p. Expected %p", head._head->_before, &b);
    cr_assert(head._head->_next == &c, "The result was %p. Expected %p", head._head->_next, &c);
    cr_assert(b._next == &a, "The result was %p. Expected %p", b._next, &a);
    cr_assert(b._before == &c, "The result was %p. Expected %p", b._before, &c);
    cr_assert(c._next == &b, "The result was %p. Expected %p", c._next, &b);
    cr_assert(c._before == &a, "The result was %p. Expected %p", c._before, &a);

}

Test(linked_list_add, add_element_rank_)
{
    head_node_t head;
    node_t a;
    node_t b;
    node_t c;

    init_linked_list(&head);
    init_node(&a);
    init_node(&b);
    init_node(&c);

    add_element_rank(&head, &a, 1);
    cr_assert(head._nb_node == 1, "The result was %d. Expected %d", head._nb_node, 1);
    cr_assert(head._head == &a, "The result was %p. Expected %p", head._head, &a);
    add_element_rank(&head, &b, 0);
    cr_assert(head._head == &b, "The result was %p. Expected %p", head._head, &b);
    cr_assert(head._nb_node == 2, "The result was %d. Expected %d", head._nb_node, 1);
    cr_assert(head._head->_before == &a, "The result was %p. Expected %p", head._head->_before, &a);
    cr_assert(head._head->_next == &a, "The result was %p. Expected %p", head._head->_next, &a);
    cr_assert(a._next == &b, "The result was %p. Expected %p", a._next, &b);
    cr_assert(a._before == &b, "The result was %p. Expected %p", a._before, &b);

    add_element_rank(&head, &c, 1);
    cr_assert(head._nb_node == 3, "The result was %d. Expected %d", head._nb_node, 1);
    cr_assert(head._head == &b, "The result was %p. Expected %p", head._head, &b);
    cr_assert(head._head->_before == &a, "The result was %p. Expected %p", head._head->_before, &a);
    cr_assert(head._head->_next == &c, "The result was %p. Expected %p", head._head->_next, &c);
    cr_assert(a._next == &b, "The result was %p. Expected %p", a._next, &b);
    cr_assert(a._before == &c, "The result was %p. Expected %p", a._before, &c);
    cr_assert(c._next == &a, "The result was %p. Expected %p", c._next, &a);
    cr_assert(c._before == &b, "The result was %p. Expected %p", c._before, &b);

}

Test(linked_list_get, get_node_)
{
    head_node_t head;
    node_t a;
    node_t b;
    node_t c;

    init_linked_list(&head);
    init_node(&a);
    init_node(&b);
    init_node(&c);

    add_element_back(&head, &a);
    add_element_back(&head, &b);
    add_element_back(&head, &c);
    cr_assert(get_node(&head, 0) == &a, "The result was %p. Expected %p", get_node(&head, 0), &a);
    cr_assert(get_node(&head, 1) == &b, "The result was %p. Expected %p", get_node(&head, 1), &b);
    cr_assert(get_node(&head, 2) == &c, "The result was %p. Expected %p", get_node(&head, 2), &c);
    cr_assert(get_node(&head, 3) == &a, "The result was %p. Expected %p", get_node(&head, 3), &a);
    cr_assert(get_node(&head, -1) == &c, "The result was %p. Expected %p", get_node(&head, -1), &c);
    cr_assert(get_node(&head, -2) == &b, "The result was %p. Expected %p", get_node(&head, -2), &b);
    cr_assert(get_node(&head, -3) == &a, "The result was %p. Expected %p", get_node(&head, -3), &a);
}

Test(linked_list_delete, clear_node_)
{
    head_node_t *head = malloc(sizeof(head_node_t));
    node_t *a = malloc(sizeof(node_t));
    node_t *b = malloc(sizeof(node_t));
    node_t *c = malloc(sizeof(node_t));

    init_linked_list(head);
    init_node(a);
    init_node(b);
    init_node(c);

    add_element_back(head, a);
    add_element_back(head, b);
    add_element_back(head, c);
    delete_node_rank(head, 0);
    cr_assert(get_node(head, 0) == b, "The result was %p. Expected %p", get_node(head, 0), b);
    cr_assert(get_node(head, 1) == c, "The result was %p. Expected %p", get_node(head, 1), c);
    clear_link(head);
    cr_assert(head->_head == NULL, "The result was %p. Expected %p", head->_head, NULL);
    delete_link(head);
}


Test(linked_list_change, change_node_value)
{
    head_node_t *head = malloc(sizeof(head_node_t));
    int int_a = 10;
    //int save_a = 10;
    float float_b = 20.5;
    //float save_b = 20.5;
    char char_c = 30;
    //char save_c = 30;
    int *pointer_d = &int_a;

    node_t *a = create_node_data(&int_a, type_int);
    node_t *b = create_node_data(&float_b, type_float);
    node_t *c = create_node_data(&char_c, type_char);
    node_t *d = create_node_data(&pointer_d, type_pointer);

    init_linked_list(head);

    add_element_back(head, a);
    add_element_back(head, b);
    add_element_back(head, c);
    add_element_back(head, d);
    change_value(a, &float_b, type_float);
    change_value(b, &int_a, type_int);
    change_value(c, &pointer_d, type_pointer);
    change_value(d, &char_c, type_char);
    cr_assert(a->_data._float == float_b, "The result was %f. Expected %f", a->_data._float, float_b);
    cr_assert(b->_data._int == int_a, "The result was %d. Expected %d", b->_data._int, int_a);
    cr_assert(c->_data._pointer == pointer_d, "The result was %p. Expected %p", c->_data._pointer, pointer_d);
    cr_assert(d->_data._char == char_c, "The result was %c. Expected %c", d->_data._char, char_c);
    cr_assert(a->_data._float == float_b, "The result was %f. Expected %f", a->_data._float, float_b);
}

Test(linked_list_get, get_node_value)
{
    head_node_t *head = malloc(sizeof(head_node_t));
    int int_a = 10;
    float float_b = 20.5;
    char char_c = 30;
    int *pointer_d = &int_a;

    node_t *a = create_node_data(&int_a, type_int);
    node_t *b = create_node_data(&float_b, type_float);
    node_t *c = create_node_data(&char_c, type_char);
    node_t *d = create_node_data(&pointer_d, type_pointer);

    init_linked_list(head);

    add_element_back(head, a);
    add_element_back(head, b);
    add_element_back(head, c);
    add_element_back(head, d);
    cr_assert(get_data(head, 0)->_int == int_a, "The result was %d. Expected %d",       get_data(head, 0)->_int, int_a);
    cr_assert(get_data(head, 1)->_float == float_b, "The result was %f. Expected %f",     get_data(head, 1)->_float, float_b);
    cr_assert(get_data(head, 2)->_char == char_c, "The result was %c. Expected %c",      get_data(head, 2)->_char, char_c);
    cr_assert(get_data(head, 3)->_pointer == pointer_d, "The result was %p. Expected %p",   get_data(head, 3)->_pointer, pointer_d);
}


Test(linked_list_cmp, get_node_from_value)
{
    head_node_t *head = malloc(sizeof(head_node_t));
    int int_a = 10;
    float float_b = 20.5;
    char char_c = 30;
    int *pointer_d = &int_a;
    char *test_lol = "bonjour";
    char *test_mdr = "bonjour";
    char *test_oui = "oui";

    node_t *a = create_node_data(&int_a, type_int);
    node_t *b = create_node_data(&float_b, type_float);
    node_t *c = create_node_data(&char_c, type_char);
    node_t *d = create_node_data(&pointer_d, type_pointer);
    node_t *e = create_node_data(&test_lol, type_array);
    node_t *f = create_node_data(&test_oui, type_array);
    init_linked_list(head);


    add_element_back(head, a);
    add_element_back(head, b);
    add_element_back(head, c);
    add_element_back(head, d);
    add_element_back(head, e);
    add_element_back(head, f);
    cr_assert(get_rank_element(head, &int_a, type_int) == 0, "The result was %d. Expected %d",          get_rank_element(head, &int_a, type_int), 0);
    cr_assert(get_rank_element(head, &float_b, type_float) == 1, "The result was %d. Expected %d",      get_rank_element(head, &float_b, type_float), 1);
    cr_assert(get_rank_element(head, &char_c, type_char) == 2, "The result was %d. Expected %d",        get_rank_element(head, &char_c, type_char), 2);
    cr_assert(get_rank_element(head, &pointer_d, type_pointer) == 3, "The result was %d. Expected %d",  get_rank_element(head, &pointer_d, type_pointer), 3);
    cr_assert(get_rank_element(head, &test_oui, type_array) == 5, "The result was %d. Expected %d",  get_rank_element(head, &test_oui, type_array), 5);
    cr_assert(get_rank_element(head, &test_mdr, type_array) == 4, "The result was %d. Expected %d",  get_rank_element(head, &test_mdr, type_array), 4);
}


