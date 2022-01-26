/*
** EPITECH PROJECT, 2022
** minishel1
** File description:
** main.c
*/

#include "./../includes/library.h"

char **add_in_array(t_var *var, char *str)
{
    int i = 0;
    char **temp = NULL;

    while (var->envp[i] != NULL) {
        i++;
    }
    temp = malloc(sizeof(char *) * i + 2);
    i = 0;
    while (var->envp[i] != NULL) {
        temp[i] = var->envp[i];
        i++;
    }
    temp[i] = str;
    temp[i + 1] = NULL;
    var->envp = temp;
    return (temp);
}

int find_str_array(t_var *var, char *to_find)
{
    int i = 0;
    int instr = 0;

    while (var->envp[i] != NULL) {
        if (find_in_str(var->envp[i], to_find) == 0)
            return (i);
        i++;
    }
    return (-1);
}

int find_in_str(char *str, char *to_find)
{
    int i = 0;
    int n = 0;

    while (str[i] != '\0' && to_find[n] != '\0') {
        if (str[i] == to_find[n])
            n++;
        else
            n = 0;
        i++;
    }
    if (n == my_strlen(to_find))
        return (0);
    return (-1);
}

char *find_func(char **paths, char *function)
{
    char *temp = NULL;
    int i = 0;
    int fd = -1;

    while (paths[i] != NULL) {
        temp = malloc(sizeof(char) * (my_strlen(paths[i])
        + my_strlen(function)) + 2);
        my_memset(temp, '\0', (my_strlen(paths[i]) + my_strlen(function)) + 2);
        temp = my_strcat(paths[i], "/");
        temp = my_strcat(temp, function);
        fd = access(temp, F_OK);
        if (fd != -1)
            return (temp);
        i++;
    }
    return ("-1");
}
