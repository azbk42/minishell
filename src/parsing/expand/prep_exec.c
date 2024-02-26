/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:48:33 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/26 15:03:01 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static size_t	count_args(t_cmd_line *cmd)
{
	t_token	*token_lst;
	size_t	count;

	count = 0;
	token_lst = cmd->token_list;
	while (token_lst)
	{
		if (token_lst->type == ARG)
			count++;
		token_lst = token_lst->next;
	}
	return (count);
}

static bool	init_tab_args(t_cmd_line *command)
{
	t_token		*token_lst;
	t_cmd_line	*cmd;
	size_t		i;

	cmd = command;
	while (cmd)
	{
		i = 0;
		cmd->args = malloc(sizeof(char *) * (count_args(cmd) + 1));
		token_lst = cmd->token_list;
		while (token_lst)
		{
			if (token_lst->type == ARG)
			{
				cmd->args[i] = ft_strdup(token_lst->token);
				if (cmd->args[i] == NULL)
					return (ERROR);
				i++;
			}
			token_lst = token_lst->next;
		}
		cmd->args[i] = NULL;
		cmd = cmd->next;
	}
	return (OK);
}

bool	prepare_execution(t_data *data)
{
	t_cmd_line	*command;

	command = data->cmd_list;
	if (init_tab_args(command) == ERROR)
	{
		ft_free_commands(command);
		data->cmd_list = NULL;
		return (ERROR);
	}
	return (OK);
}
