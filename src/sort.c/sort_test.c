/*
** EPITECH PROJECT, 2023
** organized_ripo
** File description:
** sort_test
*/

#include "../../include/shell.h"
#include "../../include/my.h"
#include <stddef.h>
#include <stdlib.h>

char *sort_param[] = {"TYPE", "NAME", "ID", NULL};
ORDER_E enum_order_tab[] = {TYPE, NAME, ID};

static int is_valid_sort_param(char *arg)
{
    for (int j = 0; sort_param[j] != NULL; j++) {
        if (!my_strcmp(arg, sort_param[j])) {
            return j;
        }
    }
    return -1;
}

static int is_reverse_flag(char *arg)
{
    if (arg == NULL)
        return 0;
    if (!my_strcmp(arg, "-r"))
        return 1;
    return 0;
}

static int fill_order(order_t *tab_order, char **args, int count_nb)
{
    int index = 0;
    int tab_index = 0;

    for (int i = 0; args[i] != NULL; i++) {
        tab_index = is_valid_sort_param(args[i]);
        if (tab_index != -1) {
            tab_order[index].order = enum_order_tab[tab_index];
            tab_order[index].is_reverse = is_reverse_flag(args[i + 1]);
            index++;
        }
        if (index >= count_nb)
            break;
    }
    return 0;
}

static void sub_malloc_tab_order(char **args, int i, int *count_param)
{
    for (int j = 0; sort_param[j] != NULL; j++) {
        if (!my_strcmp(args[i], sort_param[j]))
            (*count_param)++;
    }
}

static order_t *malloc_tab_order(char **args, int *count_param)
{
    order_t *tab_order = NULL;

    for (int i = 0; args[i] != NULL; i++) {
        sub_malloc_tab_order(args, i, count_param);
    }
    tab_order = malloc(sizeof(order_t) * ((*count_param) + 1));
    return tab_order;
}

void handle_sort_loop(order_t *tab_order, linked_list_t **head, int i)
{
    if (tab_order[i].order == TYPE) {
        if (tab_order[i].is_reverse)
            merge_sort_type_rev(head);
        else
            merge_sort_type(head);
    }
    if (tab_order[i].order == NAME) {
        if (tab_order[i].is_reverse)
            merge_sort_name_rev(head);
        else
            merge_sort_name(head);
    }
    if (tab_order[i].order == ID) {
        if (tab_order[i].is_reverse)
            merge_sort_id_rev(head);
        else
            merge_sort_id(head);
    }
}

void handle_all_sort(order_t *tab_order, linked_list_t **head,
    int tab_order_len)
{
    for (int i = tab_order_len; i >= 0; i--) {
        handle_sort_loop(tab_order, head, i);
    }
    return;
}

int sort(UNUSED void *data, UNUSED char **args)
{
    int count_param = 0;
    order_t *tab_order = malloc_tab_order(args, &count_param);
    gloabal_link_t *global = (gloabal_link_t *)data;

    if (count_param == 0)
        return 84;
    for (int i = 0; args[i] != NULL; i++) {
        if (count_param > 3)
            return 84;
        if (is_valid_sort_param(args[i]) == -1 && !is_reverse_flag(args[i]))
            return 84;
    }
    fill_order(tab_order, args, count_param);
    handle_all_sort(tab_order, &global->head, count_param);
    free(tab_order);
    return 0;
}
