/*
** EPITECH PROJECT, 2023
** organized_ripo
** File description:
** merge_split
*/
#include "../../include/shell.h"
#include "../../include/my.h"
#include <stddef.h>

void sub_split(linked_list_t **fast, linked_list_t **slow)
{
    while (*fast != NULL) {
        *fast = (*fast)->next;
        if (*fast != NULL) {
            *slow = (*slow)->next;
            *fast = (*fast)->next;
        }
    }
}

// Function to split the linked list into two halves
void split(linked_list_t *head, linked_list_t **front, linked_list_t **back)
{
    linked_list_t *slow;
    linked_list_t *fast;

    if (head == NULL || head->next == NULL) {
        *front = head;
        *back = NULL;
    } else {
        slow = head;
        fast = head->next;
        sub_split(&fast, &slow);
        *front = head;
        *back = slow->next;
        slow->next = NULL;
    }
}
