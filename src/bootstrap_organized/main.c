/*
** EPITECH PROJECT, 2023
** hunter_jam_settingup_ls (Workspace)
** File description:
** main
*/
#include "../../include/my.h"
#include "../../include/bootstrap.h"
#include <stddef.h>
#include <stdlib.h>

int main (void)
{
    int nb = 3;
    char c = 'k';
    char *str = my_strdup("Jonathan") ;
    player_t player = { my_strdup("Nau"), 98};
    linked_list_t *start = malloc(sizeof(linked_list_t));

    start->data = "hello";
    start->next = NULL;
    print_typed_value (&nb, INTEGER);
    print_typed_value (&c, CHAR);
    print_typed_value (str, STRING);
    print_typed_value (&player, PLAYER);

    push_to_list(&start, str);
    push_to_list(&start, my_strdup("aurelien"));
    display_list(start);

    return 0;
}