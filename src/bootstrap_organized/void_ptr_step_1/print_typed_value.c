/*
** EPITECH PROJECT, 2023
** hunter_jam_settingup_ls (Workspace)
** File description:
** print_typed_value
*/

#include "../../../include/bootstrap.h"
#include "../../../include/my.h"

int print_typed_value(void *data, type_t type)
{
    player_t *data_player;

    if (type == CHAR) {
        my_putchar(*(char*)data);
        my_putchar('\n');
    }
    if (type == STRING) {
        my_putstr((char*)data);
        my_putchar('\n');
    }
    if (type == INTEGER) {
        my_put_nbr(*(int*)data);
        my_putchar('\n');
    }
    if (type == PLAYER) {
        data_player = (player_t*)data;
        my_printf("%s: ", data_player->name);
        my_put_nbr(data_player->lvl);
        my_putchar('\n');
    }
    return 0;
}