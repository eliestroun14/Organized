/*
** EPITECH PROJECT, 2023
** organized
** File description:
** add
*/
#include "../../include/shell.h"
#include "../../include/my.h"
#include <stddef.h>
#include <stdlib.h>

static int handle_err(char **args)
{
    int count = 0;

    for (; args[count] != NULL; count++);
    if (count % 2 != 0)
        return 0;
    return 1;
}

static int check_type(char *arg)
{
    int i = 0;

    for (; type[i] != NULL; i++)
        if (!my_strcmp(arg, type[i])) {
            return i;
        }
    return 0;
}

static int handle_add(linked_list_t **head, char **args, int i)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));
    int j = check_type(args[i]);

    if (j == 0)
            return 0;
    if ((*head) == NULL)
        new_node->data.id = 0;
    else
        new_node->data.id = (*head)->data.id + 1;
    new_node->data.name = my_strdup(args[i + 1]);
    new_node->data.type = enum_tab[j];
    my_printf("%s n°%d - \"%s\" added.\n", type[j], new_node->data.id,
        new_node->data.name);
    new_node->next = (*head);
    (*head) = new_node;
    return 1;
}

int add(void *data, char **args)
{
    linked_list_t **head = (linked_list_t **)data;

    if (!handle_err(args))
        return 84;
    for (int i = 0; args[i] != NULL; i += 2) {
        if (!handle_add(head, args, i))
            return 84;
    }
    return 0;
}
