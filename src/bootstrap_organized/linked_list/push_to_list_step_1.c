/*
** EPITECH PROJECT, 2023
** hunter_jam_settingup_ls (Workspace)
** File description:
** push_to_list_step_1
*/

#include "../../../include/bootstrap.h"
#include "../../../include/my.h"
#include <stddef.h>
#include <stdlib.h>

void push_to_list(linked_list_t **begin, void *data)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));
    new_node->data = data;
    new_node->next = (*begin);
    (*begin) = new_node;
}