/*
** EPITECH PROJECT, 2023
** organized_ripo
** File description:
** merge_sort_id
*/
#include "../../include/shell.h"
#include "../../include/my.h"
#include <stddef.h>

linked_list_t *merge_id(linked_list_t *left, linked_list_t *right)
{
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    if (left->data.id <= right->data.id) {
        left->next = merge_id(left->next, right);
        return left;
    } else {
        right->next = merge_id(left, right->next);
        return right;
    }
}

// Merge sort function for linked list based on ID
void merge_sort_id(linked_list_t **head_ref)
{
    linked_list_t *head = *head_ref;
    linked_list_t *left;
    linked_list_t *right;

    if (head == NULL || head->next == NULL) {
        return;
    }
    split(head, &left, &right);
    merge_sort_id(&left);
    merge_sort_id(&right);
    *head_ref = merge_id(left, right);
}
