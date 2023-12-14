/*
** EPITECH PROJECT, 2023
** organized_ripo
** File description:
** merge_sort_name
*/
#include "../../include/shell.h"
#include "../../include/my.h"
#include <stddef.h>

// Function to merge two linked lists in sorted order based on NAME
linked_list_t *merge_name(linked_list_t *left, linked_list_t *right)
{
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    if (my_strcmp(left->data.name, right->data.name) < 0) {
        left->next = merge_name(left->next, right);
        return left;
    } else {
        right->next = merge_name(left, right->next);
        return right;
    }
}

// Merge sort function for linked list based on NAME
void merge_sort_name(linked_list_t **head_ref)
{
    linked_list_t *head = *head_ref;
    linked_list_t *left;
    linked_list_t *right;

    if (head == NULL || head->next == NULL) {
        return;
    }
    split(head, &left, &right);
    merge_sort_name(&left);
    merge_sort_name(&right);
    *head_ref = merge_name(left, right);
}
