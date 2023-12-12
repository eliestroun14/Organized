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

int sort(UNUSED void *data, UNUSED char **args)
{
    for (int i = 0; args[i] != NULL; i++)
        my_printf("arg[%d] = [%s]\n", i, args[i]);
    return 0;
}
