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
    gloabal_link_t tot_link;

    tot_link.nb_link = 0;
    tot_link.head = NULL;
    if (ac != 1)
        return 84;
    workshop_shell(&tot_link);
    return 0;
}
