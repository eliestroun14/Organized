/*
** EPITECH PROJECT, 2023
** organized
** File description:
** main
*/
#include "../include/my.h"
#include "../include/shell.h"
#include <stddef.h>

int main(int ac, UNUSED char const **av)
{
    linked_list_t *head = NULL;

    if (ac != 1)
        return 84;
    workshop_shell(&head);
    return 0;
}
