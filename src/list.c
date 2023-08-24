#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#include "list.h"

#define ISNONZERO(x) ((x) != 0) 
#define ISZERO(x) 	 ((x) == 0)

struct ll_node {
    intmax_t data;
    struct ll_node *next;
};

extern void *ll_append_node (struct ll_node **head, intmax_t data)
{
    while (ISNONZERO ((*head)->next)) {
        (*head) = (*head)->next;
    }
    struct ll_node *new_node = realloc (0, sizeof *new_node);

    if (ISZERO (new_node)) {
        return 0;
    }
    new_node->data = data;
    new_node->next = 0;
    (*head)->next = new_node;
    return *head;
}

extern struct ll_node *ll_build_head (size_t size,
                                      const intmax_t data[size])
{
    struct ll_node *head = 0;

    for (size_t i = 0; i < size; i++) {
        if (!ll_push_node (&head, data ? data[i] : 0)) {
            ll_delete (&head);
            return 0;
        }
    }
    return head;
}

extern size_t ll_count_occurrence (struct ll_node **head, intmax_t data)
{
    size_t count;

    for (count = 0; ISNONZERO (*head); head = &(*head)->next) {
        if ((*head)->data == data) {
            count++;
        }
    }
    return count;
}

extern void ll_delete (struct ll_node **head)
{
    assert (head);

    while (ISNONZERO (*head)) {
        struct ll_node *current = *head;

        *head = (*head)->next;
        free (current);
    }
}

extern struct ll_node *const ll_find_node (struct ll_node **head, size_t index)
{
    assert (head);

    for (size_t count = 0; ISNONZERO (*head); head = &(*head)->next) {
        if (count++ == index) {
            return *head;
        }
    }
    return 0;
}

extern intmax_t ll_get_data (struct ll_node *const *head)
{
    assert (head && *head);
    return (*head)->data;
}

extern bool ll_is_singular (struct ll_node **head)
{
    assert (head);
	return ISZERO (ll_is_empty (head)) && ISZERO ((*head)->next);
}

extern bool ll_is_empty (struct ll_node **head)
{
    assert (head);
    return ISZERO (*head);
}

extern bool ll_is_containing (struct ll_node **head, intmax_t data)
{
    assert (head && *head);

    for (; ISNONZERO (*head); head = &(*head)->next) {
        if ((*head)->data == data) {
            return true;
        }
    }
    return false;
}

extern bool ll_insert_pos (struct ll_node **head, size_t index,
                           intmax_t data)
{
    assert (head);

    if (ISZERO (*head) || ISZERO (index)) {
        return ll_push_node (head, data);
    }

    size_t count = 0;
    struct ll_node *current = *head;

    while (ISNONZERO (current) && count++ < index) {
        current = current->next;
    }
    struct ll_node *new_node = realloc (0, sizeof *new_node);

    if (ISZERO (new_node)) {
        return false;
    }
    new_node->data = data;
    new_node->next = current->next;
    current->next = new_node;
    return true;
}

extern bool ll_push_node (struct ll_node **head, intmax_t data)
{
    assert (head);

    struct ll_node *new_node = realloc (0, sizeof *new_node);

    if (ISZERO (new_node)) {
        return false;
    }
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
    return true;
}

extern int ll_print (struct ll_node **head)
{
    assert (head && *head);

    int ret_val = 0;

    for (; ISNONZERO (*head); head = &(*head)->next) {
        if (ret_val > 0) {
            ret_val += fputc ('-', stdout);
        }
        ret_val += printf (" %jd ", (*head)->data);
    }
    ret_val += fputc ('\n', stdout);
    return ret_val;
}

extern intmax_t ll_pop_node (struct ll_node **head)
{
    assert (head && *head);

    struct ll_node *current = *head;
    intmax_t data = current->data;

    *head = current->next;
    free (current);

    return data;

}

extern intmax_t ll_pop_end (struct ll_node **head)
{
    assert (head && *head);

    struct ll_node *prev = 0;
    struct ll_node *current = *head;

    while (ISNONZERO (current->next)) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    intmax_t result = current->data;

    free (current);
    return result;
}

extern intmax_t ll_pop_pos (struct ll_node **head, size_t index)
{
    assert (head && *head);

    if (ISZERO (index)) {
        return ll_pop_node (head);
    }

    struct ll_node *prev = *head;
    struct ll_node *const current = ll_find_node (&prev, index);

    /*
     * While this reduces the range of legally usable values in the 
     * list, it makes positive and negative range equally sized. 
     */
    if (ISZERO (current)) {
        return INTMAX_MIN;
    }
    while (prev->next != current) {
        prev = prev->next;
    }
    prev->next = current->next;
    intmax_t result = current->data;

    free (current);
    return result;
}

extern void ll_remove (struct ll_node **head, intmax_t data)
{
    assert (head && *head);

    while (ISNONZERO (*head)) {
        if ((*head)->data == data) {
            struct ll_node *tmp = *head;

            *head = (*head)->next;
            free (tmp);
        } else {
            head = &(*head)->next;
        }
    }
}

extern void ll_remove_dup (struct ll_node **head)
{
    assert (head && *head);

    while (ISNONZERO ((*head)->next)) {
        if ((*head)->data == (*head)->next->data) {
            struct ll_node *dup = (*head)->next;

            (*head)->next = (*head)->next->next;
            free (dup);
        }
        head = &(*head)->next;
    }
}

extern void ll_remove_if (struct ll_node **head,
                          bool (*predicate) (intmax_t data))
{
    assert (head && *head);

    while (ISNONZERO (*head)) {
        if (predicate ((*head)->data)) {
            struct ll_node *tmp = *head;

            *head = (*head)->next;
            free (tmp);
        } else {
            head = &(*head)->next;
        }
    }
}

extern void ll_replace_node (struct ll_node **head, intmax_t old_data,
                             intmax_t new_data)
{
    assert (head && *head);

    for (; ISNONZERO (*head); head = &(*head)->next) {
        if ((*head)->data == old_data) {
            (*head)->data = new_data;
            return;
        }
    }
}

extern void ll_reverse (struct ll_node **head)
{
    assert (head && *head);

    struct ll_node *new_head = 0;

    while (ISNONZERO (*head)) {
        struct ll_node *new = (*head)->next;

        (*head)->next = new_head;
        new_head = *head;
        *head = new;
    }
    *head = new_head;
}

extern intmax_t ll_size (struct ll_node **head)
{
    assert (head);

    intmax_t count;

    for (count = 0; ISNONZERO (*head); head = &(*head)->next) {
        count++;
    }
    return count;
}

extern void ll_splice (struct ll_node **list, struct ll_node **head)
{
    assert (list && head && *head);

    if (ISZERO (ll_is_empty (list))) {
        while (ISNONZERO (*head)) {
            head = &(*head)->next;
        }
        *head = *list;
    }
}

extern void ll_set_data (struct ll_node **head, intmax_t data)
{
    assert (head && *head);
    (*head)->data = data;
}


