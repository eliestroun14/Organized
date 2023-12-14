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

// Function to split the linked list into two halves
void split(linked_list_t *head, linked_list_t **start, linked_list_t **end)
{
    linked_list_t *slower;
    linked_list_t *faster;

    if (head == NULL || head->next == NULL) {
        *start = head;
        *end = NULL;
    } else {
        slower = head;
        faster = head->next;
        sub_split(&faster, &slower);
        *start = head;
        *end = slower->next;
        slower->next = NULL;
    }
}
