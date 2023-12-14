/*
** EPITECH PROJECT, 2023
** organized_ripo
** File description:
** merge_sort_id_rev
*/
#include "../../include/shell.h"
#include "../../include/my.h"
#include <stddef.h>

// Function to merge two linked lists in sorted order based on ID in reverse
linked_list_t *merge_id_rev(linked_list_t *left, linked_list_t *right)
{
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    if (left->data.id >= right->data.id) {
        left->next = merge_id_rev(left->next, right);
        return left;
    } else {
        right->next = merge_id_rev(left, right->next);
        return right;
    }
}

// Merge sort function for linked list based on ID in reverse
void merge_sort_id_rev(linked_list_t **head_ref)
{
    linked_list_t *head = *head_ref;
    linked_list_t *left;
    linked_list_t *right;

    if (head == NULL || head->next == NULL) {
        return;
    }
    split(head, &left, &right);
    merge_sort_id_rev(&left);
    merge_sort_id_rev(&right);
    *head_ref = merge_id_rev(left, right);
}
