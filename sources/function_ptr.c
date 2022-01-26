/*
** EPITECH PROJECT, 2021
** minishel1
** File description:
** main.c
*/

#include "./../includes/library.h"

void fill_flags_ls(calculator *flags)
{
    flags[0].op = "my_ls";
    flags[0].ptr = &my_lsfunc;
    flags[1].op = "my_cd";
    flags[1].ptr = &cd_func;
    flags[2].op = "my_pwd";
    flags[2].ptr = &my_pwdfunc;
    flags[3].op = "ls";
    flags[3].ptr = &lsfunc;
    flags[4].op = "cd";
    flags[4].ptr = &cd_func;
    flags[5].op = "env";
    flags[5].ptr = &env_func;
    flags[6].op = "pwd";
    flags[6].ptr = &pwdfunc;
    flags[7].op = "setenv";
    flags[7].ptr = &setenv_func;
    flags[8].op = "unsetenv";
    flags[8].ptr = &unsetenv_func;
    flags[9].op = "exit";
    flags[9].ptr = &exit_func;
}

int func_pointer_ls(t_var *var, char *params, char *type)
{
    int i = 0;

    calculator flags[10];
    fill_flags_ls(flags);
    while (i < 10) {
        if (my_strcmp(type, flags[i].op) == 0) {
            (*(flags[i].ptr))(var, params);
        }
        i++;
    }
    return (0);
}
