/*
** EPITECH PROJECT, 2023
** organized
** File description:
** sort
*/
#include "../../include/shell.h"
#include "../../include/my.h"
#include <stddef.h>
#include <stdlib.h>

char *sort_param[] = {"TYPE", "NAME", "ID", NULL};
ORDER_E enum_order_tab[] = {TYPE, NAME, ID};

static int handle_err_sort(char *arg)
{
    for (int j = 0; sort_param[j] != NULL; j++)
        if (!my_strcmp(arg, sort_param[j]) || !my_strcmp(arg, "-r"))
            return 1;
    return 0;
}

order_t *malloc_tab_order(char **args, int *count_param)
{
    order_t *tab_order = NULL;

    for (int i = 0; args[i] != NULL; i++) {
        for (int j = 0; sort_param[j] != NULL; j++) {
            if (!my_strcmp(args[i], sort_param[j]))
                (*count_param)++;
        }
    }
    tab_order = malloc(sizeof(order_t) * ((*count_param) + 1));
    return tab_order;
}

int get_order(char *arg)
{
    for (int i = 0; sort_param[i] != NULL; i++) {
        if (!my_strcmp(arg, sort_param[i]))
            return enum_order_tab[i];
    }
    return -1;
}

int get_reverse(char **args, int i)
{
    if (args[i] == NULL)
        return 0;
    if (!my_strcmp(args[i], "-r"))
        return 1;
    else
        return 0;
}

int fill_order(order_t **tab_order, char **args, int count_param)
{
    for (int i = 0; i < count_param; i++) {
        for (int j = 0; args[j] != NULL; j++) {
            tab_order[i]->order = get_order(args[j]);
            tab_order[i]->is_reverse = get_reverse(args, j + 1);
        }
    }
    return 0;
}

int handle_sort(linked_list_t **head, char **args)
{
    return 0;
}

int sort(UNUSED void *data, UNUSED char **args)
{
    //int count_param = 0;
    //order_t *tab_order = malloc_tab_order(args, &count_param);
    gloabal_link_t *global = (gloabal_link_t *)data;

    if (args[0] == NULL || !my_strcmp(args[0], "-r"))
        return 84;
    for (int i = 0; args[i] != NULL; i++)
        if (!handle_err_sort(args[i]))
            return 84;

    handle_sort(&global->head, args)
    return 0;
}
