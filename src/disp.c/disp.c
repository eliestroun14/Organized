/*
** EPITECH PROJECT, 2023
** organized
** File description:
** disp
*/
#include "../../include/shell.h"
#include "../../include/my.h"
#include <stddef.h>
#include <stdlib.h>

int disp(void *data, char **args)
{
    linked_list_t *tmp = *((linked_list_t **)data);

    while (tmp != NULL) {
        my_printf("%s n°%d - \"%s\"\n", type[(tmp)->data.type],
        tmp->data.id, tmp->data.name);
        printf("%p\n", tmp);
        printf("%p\n", tmp->next);
        
        tmp = tmp->next;
    }
    return 0;
}