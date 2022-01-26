/*
** EPITECH PROJECT, 2022
** minishel1
** File description:
** main.c
*/

#include "./../includes/library.h"

void env_func(t_var *var, char *params)
{
    for (int i = 0; var->envp[i] != NULL; i++)
        my_putstr(var->envp[i]);
        my_putstr("\n");
}

void setenv_func(t_var *var, char *params)
{
    char **param = get_env_params(params);
    char *temp = NULL;
    int i = -1;

    if (param[0] == NULL)
        env_func(var, params);
    else {
        i = find_str_array(var, param[0]);
        if (i == -1) {
            if (param[1] == NULL) {
                param[0] = my_strcat(param[0], "=");
                add_in_array(var, param[0]);
            } else {
                param[0] = my_strcat(param[0], "=");
                param[0] = my_strcat(param[0], param[1]);
                add_in_array(var, param[0]);
            }
        } else {
            i = find_str_array(var, param[0]);
            if (param[1] == NULL) {
                temp = my_strdup(param[0]);
                temp = my_strcat(temp, "=");
                var->envp[i] = temp;
            } else {
                temp = my_strdup(param[0]);
                temp = my_strcat(temp, "=");
                temp = my_strcat(temp, param[1]);
                var->envp[i] = temp;
            }
        }
    }
}

void unsetenv_func(t_var *var, char *params)
{
    char **param = get_env_params(params);
    char **temp = NULL;
    int i = -1;
    int n = 0;
    int x = 0;

    for (x = 0; var->envp[x] != NULL; x++)
    temp = malloc(sizeof(char *) * x);
    x = 0;
    if (param[0] == NULL)
        env_func(var, params);
    else {
        i = find_str_array(var, param[0]);
        if (i != -1) {
            while (var->envp[x] != NULL) {
                if (n == i)
                    x++;
                temp[n] = var->envp[x];
                x++;
                n++;
            }
        }
        temp[n] = NULL;
        var->envp = temp;
    }
}
