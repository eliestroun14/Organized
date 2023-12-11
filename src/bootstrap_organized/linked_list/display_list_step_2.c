/*
** EPITECH PROJECT, 2023
** hunter_jam_settingup_ls (Workspace)
** File description:
** display_list
*/
#include "../../../include/bootstrap.h"
#include "../../../include/my.h"
#include <stddef.h>
#include <stdlib.h>

void display_list(linked_list_t *begin)
{
    linked_list_t *tmp = begin;

    while (tmp != NULL) {
        print_typed_value(tmp->data, STRING);
        tmp = tmp->next;
    }
}
