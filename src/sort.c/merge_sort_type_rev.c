/*
** EPITECH PROJECT, 2023
** organized_ripo
** File description:
** merge_sort_type_rev
*/
#include "../../include/shell.h"
#include "../../include/my.h"
#include <stddef.h>

linked_list_t *merge_type_rev(linked_list_t *left, linked_list_t *right)
{
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    if (left->data.type >= right->data.type) {
        left->next = merge_type_rev(left->next, right);
        return left;
    } else {
        right->next = merge_type_rev(left, right->next);
        return right;
    }
}

void merge_sort_type_rev(linked_list_t **head_ref)
{
    linked_list_t *head = *head_ref;
    linked_list_t *left;
    linked_list_t *right;

    if (head == NULL || head->next == NULL) {
        return;
    }
    split(head, &left, &right);
    merge_sort_type_rev(&left);
    merge_sort_type_rev(&right);
    *head_ref = merge_type_rev(left, right);
}
