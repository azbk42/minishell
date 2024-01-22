/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:13:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/22 19:34:40 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>

char *str_join(char *a, char *b, char *c)
{
    size_t size;
    char *res;

    size = ft_strlen(a) + ft_strlen(b) + ft_strlen(c) + 1;
    res = malloc(size);
    if (!res)
        return (NULL);
    strcpy(res, a);
    strcat(res, b);
    strcat(res, c);
    return (res);
}

char *find_command(char *dir, char *cmd)
{
    char *full_path;

    full_path = str_join(dir, "/", cmd);
    if (!full_path)
        return (NULL);
    if (access(full_path, X_OK) == 0)
        return (full_path);
    free(full_path);
    return (NULL);
}

char *find_command_in_path(char *cmd)
{
    char *path;
    char *path_copy;
    char *dir;
    char *found;

    path = getenv("PATH");
    path_copy = strdup(path);
    if (!path_copy)
        return (NULL);
    dir = strtok(path_copy, ":");
    while (dir != NULL)
    {
        found = find_command(dir, cmd);
        if (found != NULL)
        {
            free(path_copy);
            return (found);
        }
        dir = strtok(NULL, ":");
    }
    free(path_copy);
    return (NULL);
}

void split_command(char *cmd, char *argv[], int max_args)
{
    int i;
    char *token;

    i = 0;
    token = cmd;
    while (token != NULL && i < max_args - 1)
    {
        argv[i++] = token;
        token = strchr(token, ' ');
        if (token != NULL)
        {
            *token = '\0';
            token++;
            while (*token == ' ')
                token++;
        }
    }
    argv[i] = NULL;
}

void execute_child_process(char *const argv[], char **env)
{
    if (execve(argv[0], argv, env) < 0)
    {
        perror("Erreur d'execve");
        exit(EXIT_FAILURE);
    }
}

void wait_for_child(pid_t pid)
{
    int status;

    waitpid(pid, &status, WUNTRACED);
    while (!WIFEXITED(status) && !WIFSIGNALED(status))
        waitpid(pid, &status, WUNTRACED);
}

void execute_command(char *cmd, char **env)
{
    char *argv[64];
    char *full_path;
    pid_t pid;

    split_command(cmd, argv, 64);
    full_path = find_command_in_path(argv[0]);
    if (!full_path)
    {
        printf("Commande '%s' non trouvée\n", argv[0]);
        return;
    }
    argv[0] = full_path;
    pid = fork();
    if (pid < 0)
    {
        perror("Erreur de fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
        execute_child_process(argv, env);
    else
        wait_for_child(pid);
    free(full_path);
}


int main() 
{
    char *line;
    char **env;

    env = NULL;
    while (true) 
    {
        line = readline("\001\033[1;33m\002MonMinishell>\001\033[0m\002 ");
        if (line == NULL) 
        {
            printf("\nCtrl+D détecté. Au revoir !\n");
            break;
        }
        if (line != NULL && strlen(line) > 0) 
        {
            printf("Commande saisie : %s\n", line);
            execute_command(line, env);
            add_history(line);
        }
        free(line);
    }
    return 0;
}
