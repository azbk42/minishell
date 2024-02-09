/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:13:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/09 20:52:23 by azbk             ###   ########.fr       */
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


t_token *create_token(char *word, t_e_token type) {

    t_token *token = (t_token *)malloc(sizeof(t_token));
    
    token->token = ft_strdup(word);
    token->type = type;
    token->next = NULL;
    return token;
}


void init_data(t_data *data) {
    // Allouer de la mémoire pour data->cmd
    data->cmd_list = malloc(sizeof(t_cmd_line));

    // Initialiser data->cmd
    data->cmd_list->cmd = NULL;
    data->cmd_list->token_list = NULL;
    data->cmd_list->args = NULL;
    data->cmd_list->next = NULL;
    
    // Créer les nœuds t_token et les lier pour la première commande
    t_token *token0 = create_token("'slt''yo'\"Bonjour $$ $USERR PloP\"", ARG);
    // t_token *token1 = create_token("        \"la variable '$USER' est au nom de emauduit\"      ", ARG);
    // t_token *token2 = create_token("\"Bonjour'$USER'\"ELOUAN'\"YES'", FILE_OUT);
    // t_token *token3 = create_token("txt.txt", WRITE_FILE);

    // Lier les nœuds t_token pour la première commande
    // token0->next = token1;
    // token1->next = token2;
    // token2->next = token3;

    // Attribuer le premier nœud t_token à data->cmd->token_list
    data->cmd_list->token_list = token0;

    // Créer une nouvelle commande avec sa propre liste de jetons pour la deuxième commande
    // data->cmd_list->next = malloc(sizeof(t_cmd_line));
    // data->cmd_list->next->cmd = NULL;
    // data->cmd_list->next->token_list = NULL;
    // data->cmd_list->next->args = NULL;
    // data->cmd_list->next->next = NULL;

    // // Créer les nœuds t_token et les lier pour la deuxième commande
    // t_token *t_0 = create_token("wc", ARG);
    // t_token *t_1 = create_token("-c", ARG);
    // t_token *t_2 = create_token(">", FILE_OUT);
    // t_token *t_3 = create_token("lol.txt", WRITE_FILE);

    // // Lier les nœuds t_token pour la deuxième commande
    // t_0->next = t_1;
    // t_1->next = t_2;
    // t_2->next = t_3;

    // // Attribuer le premier nœud t_token à la liste de jetons de la deuxième commande
    // data->cmd_list->next->token_list = t_0;
}


int main(int ac, char **av) 
{    
    t_data *data;
    t_token *current_token;
    t_cmd_line *command;
    
    if (ac == 0 || !av)
        return (0);
    data = malloc(sizeof(t_data)); 
    data->cmd_list = NULL;
    data->t = NULL;
    init_data(data);
    // env = init_env(envp);
    // if (!env)
    //     return (1);
    expand_all_token(data);
    
    command = data->cmd_list;
    while (command)
    {
        current_token = command->token_list;
        while (current_token) 
        {
            //printf("%s\n", current_token->token);
            current_token = current_token->next;
        }
        command = command->next;
    }
    // while (true) 
    // {
    //     line = readline("\001\033[1;33m\002MonMinishell>\001\033[0m\002 ");   
    //     if (line == NULL) 
    //     {
    //         printf("\nCtrl+D détecté. Au revoir !\n");
    //         break;
    //     }
    //     if (ft_strncmp(line, "exit", 5) == 0) 
	// 	{
    //         free(line);
    //         break;
    //     }
        
    //     if (line != NULL && strlen(line) > 0) 
    //     {
    //         printf("Commande saisie : %s\n", line);
    //         execute_command(line, env);
    //         add_history(line);
    //     }
    //     free(line);
    // }
    return (0);
}

