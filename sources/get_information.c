/*
** EPITECH PROJECT, 2021
** minishel1
** File description:
** main.c
*/

#include "./../includes/library.h"

int get_line_function(t_var *var)
{
    int bytes_read;
    size_t size = 18;
    char *string = NULL;
    char *command = NULL;
    char *params = NULL;

    my_putstr("$> ");
    string = (char *) malloc (size);
    bytes_read = getline(&string, &size, stdin);
    if (bytes_read < 0)
        exit_func(var, command);
    string[my_strlen(string) - 1] = '\0';
    if (bytes_read == -1) {
        exit(84);
    } else {
        command = get_command(string);
        params = get_params(string);
        func_pointer_ls(var, params, command);
    }
    return (0);
}

char *get_params(char *str)
{
    char *comand = malloc(sizeof(char) * 100);
    int i = 0;
    int n = 0;
    my_memset(comand, '\0', 100);

    while (str[i] != ' ' && str[i] != '\0') {
        i++;
    }
    if (str[i] == '\0')
        return (NULL);
    i++;
    while (str[i] != '\0')
        comand[n++] = str[i++];
    return (comand);
}

char *get_command(char *str)
{
    char *comand = malloc(sizeof(char) * 100);
    int i = 0;
    my_memset(comand, '\0', 100);

    while (str[i] != ' ' && str[i] != '\0') {
        comand[i] = str[i];
        i++;
    }
    return (comand);
}

int get_path(char *str)
{
    char *comand = malloc(sizeof(char) * my_strlen(str));
    int i = 0;
    my_memset(comand, '\0', my_strlen(str));

    while (str[i] != '=' && str[i] != '\0') {
        comand[i] = str[i];
        i++;
    }
    if (my_strcmp(comand, "PATH") == 0)
        return (1);
    return (-1);
}

char **get_env_params(char *str)
{
    char **comand = malloc(sizeof(char *) * 3);
    int i = 0;
    int n = 0;

    if (str == NULL) {
        comand[0] = NULL;
        comand[1] = NULL;
        return (comand);
    }
    comand[0] = malloc(sizeof(char) * my_strlen(str));
    comand[1] = malloc(sizeof(char) * my_strlen(str));
    comand[2] = NULL;
    my_memset(comand[0], '\0', my_strlen(str));
    my_memset(comand[1], '\0', my_strlen(str));
    while (str[i] != ' ') {
        if (str[i] == '\0') {
            comand[1] = NULL;
            return (comand);
        } else {
            comand[0][i] = str[i];
            i++;
        }
    }
    i++;
    while (str[i] != '\0') {
        comand[1][n] = str[i];
        n++;
        i++;
    }
    return (comand);
}
