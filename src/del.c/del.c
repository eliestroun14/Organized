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
#include <stdbool.h>

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

static int handle_del(char *args, linked_list_t *previous,
    linked_list_t **begin, linked_list_t *tmp)
{
    if (my_getnbr(args) == tmp->data.id) {
        if (previous == NULL) {
            del_head(tmp, begin);
            return 1;
        }
        if (tmp->next == NULL) {
            del_tail(tmp, previous);
            return 1;
        } else {
            print_del(tmp);
            free(tmp->data.name);
            previous->next = tmp->next;
            free(tmp);
            return 1;
        }
    }
    return 0;
}

static int handle_err_del(char *arg)
{
    for (int j = 0; arg[j] != '\0'; j++) {
        if (!is_digit(arg[j]))
            return 84;
    }
    return 0;
}

void check_del(char *arg, linked_list_t **previous,
    gloabal_link_t **global, linked_list_t **tmp)
{
    if (!handle_del(arg, *previous, &(*global)->head, *tmp)) {
        *previous = *tmp;
        return;
    }
    return;
}

int handle_all_err_del(char **args)
{
    if (args[0] == NULL)
        return 84;
    for (int i = 0; args[i] != NULL; i++)
        if (handle_err_del(args[i]) == 84)
            return 84;
    return 0;
}

int del(void *data, UNUSED char **args)
{
    gloabal_link_t *global = (gloabal_link_t *)data;
    linked_list_t *tmp;
    linked_list_t *previous;
    linked_list_t *savior;

    if (handle_all_err_del(args) == 84)
        return 84;
    for (int i = 0; args[i] != NULL; i++) {
        tmp = global->head;
        previous = NULL;
        while (tmp != NULL) {
            savior = tmp->next;
            check_del(args[i], &previous, &global, &tmp);
            tmp = savior;
        }
    }
    return 0;
}
