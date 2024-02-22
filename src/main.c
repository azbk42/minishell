/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:13:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/22 15:13:18 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

t_token	*create_token(char *word, t_e_token type)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	token->token = ft_strdup(word);
	token->type = type;
	token->jump = 0;
	token->next = NULL;
	return (token);
}

void	init_data(t_data *data)
{
	t_token	*token0;
	t_token	*token1;

	// Allouer de la mémoire pour data->cmd
	data->cmd_list = malloc(sizeof(t_cmd_line));
	// Initialiser data->cmd
	data->cmd_list->cmd = NULL;
	data->cmd_list->token_list = NULL;
	data->cmd_list->args = NULL;
	data->cmd_list->next = NULL;
	// Créer les nœuds t_token et les lier pour la première commande
	// token0 = create_token("  $KK'salut''yo'$KK$LOL$USER ", ARG);
	// token1 = create_token("      $KK  ", ARG);

	token0 = create_token("  slt$KK\"$KK\"$KK$O'bonjour' ", ARG);
	token1 = create_token("      $KK  ", ARG);
	token0->next = token1;
	
	data->cmd_list->token_list = token0;
}

int	main(int ac, char **av, char **envp)
{
	t_data		*data;
	t_token		*current_token;
	t_cmd_line	*command;
	t_env		**env;
	//t_env **secret;
	int			i;

	if (ac == 0 || !av)
		return (0);
	data = malloc(sizeof(t_data));
	data->cmd_list = NULL;
	data->t = NULL;
	ft_init_lst_env((const char **)envp);
	env = ft_singletone_env();
	//secret = dup_secret_env(env);
	init_data(data);
	if (expand_all_tokens(data) == ERROR)
		ft_free_data(data);
	
	ft_free_env_singletone(env);
	//ft_free_secret_env(secret);	

	command = data->cmd_list;
	i = 0;
	while (command)
	{
		current_token = command->token_list;
		while (current_token)
		{
			printf("token[%d] = %s\n", ++i, current_token->token);
			current_token = current_token->next;
		}
		command = command->next;
	}
	ft_free_data(data);
	return (0);
}
