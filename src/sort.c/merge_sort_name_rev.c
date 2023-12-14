/*
** EPITECH PROJECT, 2023
** organized_ripo
** File description:
** merge_sort_name_rev
*/
#include "../../include/shell.h"
#include "../../include/my.h"
#include <stddef.h>

linked_list_t *merge_name_rev(linked_list_t *left, linked_list_t *right)
{
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    if (my_strcmp(left->data.name, right->data.name) >= 0) {
        left->next = merge_name_rev(left->next, right);
        return left;
    } else {
        right->next = merge_name_rev(left, right->next);
        return right;
    }
}

void merge_sort_name_rev(linked_list_t **head_ref)
{
    linked_list_t *head = *head_ref;
    linked_list_t *left;
    linked_list_t *right;

    if (head == NULL || head->next == NULL) {
        return;
    }
    split(head, &left, &right);
    merge_sort_name_rev(&left);
    merge_sort_name_rev(&right);
    *head_ref = merge_name_rev(left, right);
}
