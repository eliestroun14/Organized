/*
** EPITECH PROJECT, 2023
** organized_ripo
** File description:
** merge_sort_name_rev
*/
#include "../../include/shell.h"
#include "../../include/my.h"
#include <stddef.h>

linked_list_t *merge_name_rev(linked_list_t *left_split,
    linked_list_t *right_split)
{
    if (left_split == NULL) {
        return right_split;
    }
    if (right_split == NULL) {
        return left_split;
    }
    if (my_strcmp(left_split->data.name, right_split->data.name) >= 0) {
        left_split->next = merge_name_rev(left_split->next, right_split);
        return left_split;
    } else {
        right_split->next = merge_name_rev(left_split, right_split->next);
        return right_split;
    }
}

void merge_sort_name_rev(linked_list_t **head_ref)
{
    linked_list_t *head = *head_ref;
    linked_list_t *left_split;
    linked_list_t *right_split;

    if (head == NULL || head->next == NULL) {
        return;
    }
    split(head, &left_split, &right_split);
    merge_sort_name_rev(&left_split);
    merge_sort_name_rev(&right_split);
    *head_ref = merge_name_rev(left_split, right_split);
}
