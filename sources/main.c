/*
** EPITECH PROJECT, 2021
** minishel1
** File description:
** main.c
*/

#include "./../includes/library.h"

char **paths(char *str)
{
    char **result = malloc(sizeof(char *) * 100);
    int i = 5;
    int n = 0;
    int j = 0;

    while (str[i] != '\0') {
        result[n] = malloc(sizeof(char) * my_strlen(str));
        j = 0;
        my_memset(result[n], '\0', my_strlen(str));
        while (str[i] != ':' && str[i] != '\0') {
            result[n][j++] = str[i++];
        }
        i++;
        n++;
    }
    result[n] = NULL;
    return (result);
}

char *exercise_one(int argc, char **argv, char **envp)
{
    char *thisEnv = NULL;

    for (char **env = envp; *env != 0; env++) {
        thisEnv = *env;
        if (get_path(thisEnv) == 1)
            return (thisEnv);
    }
    return thisEnv;
}

void print_arg(char ** arg)
{
    int i = 0;

    while (arg[i] != NULL)
    {
        my_putstr(arg[i]);
        i++;
    }
}

int status(char *str)
{
    int status = system(str);

    return (status);
}

int main(int argc, char **argv, char **envp)
{
    t_var var;

    var.argv = argv;
    var.envp = envp;
    var.argc = argc;
    while (1)
    {
        get_line_function(&var);
    }
    return (0);
}
