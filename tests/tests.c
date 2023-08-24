#include <criterion/criterion.h>
#include <stdint.h>
#include "../src/list.h"

#define SIZE 10

struct ll_node *head = 0;

void setup (void)
{
    intmax_t limits[SIZE];

    for (intmax_t i = 0; i < SIZE; i++) {
        limits[i] = i;
    }

    head = ll_build_head (SIZE, limits);
    cr_assert (head);
}

void tear_down (void)
{
    ll_delete (&head);
}

TestSuite (list_tests, .init = setup, .fini = tear_down);

Test (list_tests, ll_reverse) 
{
	ll_reverse (&head);
	cr_assert (ll_print (&head) > 0);
	cr_assert (!ll_pop_node (&head));
}

Test (list_tests, ll_splice) 
{
	struct ll_node *new = ll_build_head (SIZE, 0);
	cr_assert (new);
	ll_splice (&new, &head);
	cr_assert (ll_print(&head) > 0);
}

bool predicate (intmax_t data) 
{
	return data % 2 == 0 ? true : false;
}

Test (list_tests, ll_remove) 
{
	cr_assert (ll_insert_pos (&head, 1, 4));
	ll_remove (&head, 4);
	cr_assert (!ll_is_containing (&head, 4));
}

Test (list_tests, ll_remove_if) 
{
	ll_remove_if (&head, predicate);
	cr_assert (!ll_is_containing (&head, 2) && !ll_is_containing (&head, 4) 
				&& !ll_is_containing (&head, 6) && !ll_is_containing (&head, 8)
				&& !ll_is_containing (&head, 0));
}

Test (list_tests, ll_remove_dup) 
{
	cr_assert (ll_insert_pos (&head, 5, 4));	
	ll_remove_dup (&head);
	cr_assert (ll_print (&head) > 0);
}

Test (list_tests, ll_push_node)
{
    cr_assert (ll_push_node (&head, -18));
    cr_assert (ll_push_node (&head, 4929320493214));
    cr_assert (ll_push_node (&head, 0));
    cr_assert (ll_push_node (&head, -3021302324));
    cr_assert (ll_push_node (&head, 450340));
}

Test (list_tests1, ll_is_empty) 
{
	struct ll_node *head = 0;
	cr_assert (ll_is_empty (&head));
}

Test (list_tests1, ll_is_singular) 
{
	struct ll_node *head = 0;
	cr_assert (ll_push_node (&head, 5));
	cr_assert (ll_is_singular (&head));
	ll_delete (&head);
}

Test (list_tests, ll_count_occurrence) 
{
	cr_assert (ll_push_node (&head, 2));
	cr_assert (ll_count_occurrence (&head, 2) == 2);
}

Test (list_tests, ll_print)
{
	cr_assert (ll_print (&head) > 0);
}

Test (list_tests, ll_find_node)
{
    struct ll_node *const current = ll_find_node (&head, 0);

    cr_assert (current && ll_get_data (&current) == 9);

    struct ll_node *const new = ll_find_node (&head, 9);
    cr_assert (new && !ll_get_data (&new));
}

Test (list_tests, ll_set_data)
{
    struct ll_node *current = ll_find_node (&head, 0);

    ll_set_data (&current, 1);
    cr_assert (ll_pop_node (&head) == 1);
}

Test (list_tests, ll_pop_node)
{
    cr_assert (ll_pop_node (&head) == 9);
    cr_assert (!ll_is_containing (&head, 9));
}

Test (list_tests, ll_size)
{
    cr_assert (ll_size (&head) == SIZE);
    // cr_assert (!ll_size (0));
}

Test (list_tests, ll_replace_node)
{
    ll_replace_node (&head, 9, 90);
}

Test (list_tests, ll_append_node)
{
    ll_append_node (&head, 30);
	cr_assert (ll_pop_end (&head) == 30);
}

Test (list_tests, ll_insert_pos)
{
    cr_assert (ll_insert_pos (&head, 0, 333));
    cr_assert (ll_is_containing (&head, 333));

    cr_assert (ll_insert_pos (&head, 10, 444));
    cr_assert (ll_is_containing (&head, 444));
}

Test (list_tests, ll_pop_end)
{
    cr_assert (ll_pop_end (&head) == 0);
    cr_assert (!ll_is_containing (&head, 0));
}

Test (list_tests, ll_pop_pos)
{
    cr_assert (ll_pop_pos (&head, 0) == 9);
    cr_assert (!ll_is_containing (&head, 9));

    cr_assert (ll_pop_pos (&head, 1) == 7);
    cr_assert (!ll_is_containing (&head, 7));

    cr_assert (ll_pop_pos (&head, 2) == 5);
    cr_assert (!ll_is_containing (&head, 5));
}

Test (list_tests, ll_is_containing)
{
    //cr_assert (!ll_is_containing (0, 4));
    cr_assert (!ll_is_containing (&head, 3912932));
    cr_assert (!ll_is_containing (&head, -893821));
    cr_assert (ll_is_containing (&head, 9));
    cr_assert (ll_is_containing (&head, 4));
    //cr_assert (!ll_is_containing (0, 0));
    cr_assert (!ll_is_containing (&head, 39283108883088311209));
}

