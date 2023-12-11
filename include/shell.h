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

typedef struct organize_s {
    TYPE_e type;
    char *name;
    int id;
} organize_t;

typedef struct linked_list_s {
    struct linked_list_s *previous;
    organize_t data;
    struct linked_list_s *next;
} linked_list_t;

USED static char const *type[] = {"ACTUATOR", "DEVICE", "PROCESSOR",
    "SENSOR", "WIRE", NULL};
USED static TYPE_e enum_tab[] = {ACTUATOR, DEVICE, PROCESSOR, SENSOR, WIRE };

// To be implemented
int add(void *data, char **args);
int del(void *data, char **args);
int sort(void *data, char **args);
int disp(void *data, char **args);

// Already implemented
int workshop_shell(void *data);

#endif /* SHELL_H */