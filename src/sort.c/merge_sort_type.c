/*
** EPITECH PROJECT, 2023
** organized_ripo
** File description:
** merge_sort_type
*/

#include "../../include/shell.h"
#include "../../include/my.h"
#include <stddef.h>

linked_list_t *merge_type(linked_list_t *left, linked_list_t *right)
{
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    if (left->data.type <= right->data.type) {
        left->next = merge_type(left->next, right);
        return left;
    } else {
        right->next = merge_type(left, right->next);
        return right;
    }
}

void merge_sort_type(linked_list_t **head_ref)
{
    linked_list_t *head = *head_ref;
    linked_list_t *left;
    linked_list_t *right;

    if (head == NULL || head->next == NULL) {
        return;
    }
    split(head, &left, &right);
    merge_sort_type(&left);
    merge_sort_type(&right);
    *head_ref = merge_type(left, right);
}
