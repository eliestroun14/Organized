/*
** EPITECH PROJECT, 2023
** organized
** File description:
** del
*/
#include "../../include/shell.h"
#include "../../include/my.h"
#include <stddef.h>
#include <stdlib.h>

static void print_del(linked_list_t *tmp)
{
    my_printf("%s n°%d - \"%s\" deleted.\n", type[tmp->data.type],
        tmp->data.id, tmp->data.name);
}

static void del_head(linked_list_t *tmp, linked_list_t **begin)
{
    print_del(tmp);
    *begin = tmp->next;
    free(tmp->data.name);
    free(tmp);
    return;
}

static void del_tail(linked_list_t *tmp, linked_list_t *previous)
{
    print_del(tmp);
    previous->next = NULL;
    free(tmp->data.name);
    free(tmp);
    return;
}

static void handle_del(char *args, linked_list_t *previous,
    linked_list_t **begin, linked_list_t *tmp)
{
    if (my_getnbr(args) == tmp->data.id) {
        if (previous == NULL) {
            del_head(tmp, begin);
            return;
        }
        if (tmp->next == NULL) {
            del_tail(tmp, previous);
            return;
        } else {
            print_del(tmp);
            free(tmp->data.name);
            previous->next = tmp->next;
            free(tmp);
            return;
        }
    }
}

int del(void *data, UNUSED char **args)
{
    linked_list_t **begin = ((linked_list_t **)data);
    linked_list_t *tmp;
    linked_list_t *previous;

    for (int i = 0; args[i] != NULL; i++) {
    tmp = *begin;
    previous = NULL;
        while (tmp != NULL) {
            handle_del(args[i], previous, begin, tmp);
            previous = tmp;
            tmp = tmp->next;
        }
    }
    return 0;
}
