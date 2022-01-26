/*
** EPITECH PROJECT, 2021
** sebastia header
** File description:
** fgfghgf
*/

#ifndef STRUCTS_H_
    #define STRUCTS_H_
    #include <time.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    typedef struct s_var {
        int argc;
        char **argv;
        char **envp;
    } t_var;

    typedef struct do_op {
        char *op;
        void (*ptr)(t_var *var, char *params);
    } calculator;

#endif
