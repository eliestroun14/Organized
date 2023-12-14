/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H
    #define UNUSED __attribute__ ((unused))
    #define USED __attribute__ ((used))

    #include <stddef.h>

typedef enum TYPE_s {
    ACTUATOR,
    DEVICE,
    PROCESSOR,
    SENSOR,
    WIRE
} TYPE_e;

typedef enum ORDER {
    EMPTY,
    TYPE,
    NAME,
    ID
} ORDER_E;

typedef struct order_s {
    ORDER_E order;
    int is_reverse;
} order_t;

typedef struct organize_s {
    TYPE_e type;
    char *name;
    int id;
} organize_t;

typedef struct linked_list_s {
    organize_t data;
    struct linked_list_s *next;
} linked_list_t;

typedef struct gloabal_link_s {
    linked_list_t *head;
    int nb_link;
} gloabal_link_t;

USED static char const *type[] = {"ACTUATOR", "DEVICE", "PROCESSOR",
    "SENSOR", "WIRE", NULL};
USED static TYPE_e enum_tab[] = {ACTUATOR, DEVICE, PROCESSOR, SENSOR, WIRE };

// To be implemented
int add(void *data, char **args);
int del(void *data, char **args);
int sort(void *data, char **args);
int disp(void *data, char **args);

// split merge
void split(linked_list_t *head, linked_list_t **front, linked_list_t **back);

// merge sorts
void merge_sort_id(linked_list_t **head_ref);
void merge_sort_id_rev(linked_list_t **head_ref);
void merge_sort_type(linked_list_t **head_ref);
void merge_sort_type_rev(linked_list_t **head_ref);
void merge_sort_name(linked_list_t **head_ref);
void merge_sort_name_rev(linked_list_t **head_ref);

// Already implemented
int workshop_shell(void *data);

#endif /* SHELL_H */
