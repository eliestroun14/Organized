/*
** EPITECH PROJECT, 2023
** organized_ripo
** File description:
** merge_split
*/
#include "../../include/shell.h"
#include "../../include/my.h"
#include <stddef.h>

void sub_split(linked_list_t **faster, linked_list_t **slower)
{
    while (*faster != NULL) {
        *faster = (*faster)->next;
        if (*faster != NULL) {
            *slower = (*slower)->next;
            *faster = (*faster)->next;
        }
    }
}

void split(linked_list_t *head, linked_list_t **pt_left,
    linked_list_t **pt_right)
{
    linked_list_t *slower;
    linked_list_t *faster;

    if (head == NULL || head->next == NULL) {
        *pt_left = head;
        *pt_right = NULL;
    } else {
        slower = head;
        faster = head->next;
        sub_split(&faster, &slower);
        *pt_left = head;
        *pt_right = slower->next;
        slower->next = NULL;
    }
}
