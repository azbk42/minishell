/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:43:47 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/12 14:57:34 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_tokens(t_token *tokens)
{
	t_token	*cur;
	t_token	*next;

	cur = tokens;
	while (cur != NULL)
	{
		next = cur->next;
		free(cur->token);
		free(cur);
		cur = next;
	}
}

void	ft_free_array(char **tab)
{
	size_t	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	ft_free_cmd(t_cmd_line *cmd)
{
	free(cmd->cmd);
	ft_free_tokens(cmd->token_list);
	ft_free_array(cmd->args);
	free(cmd);
}

void	ft_free_commands(t_cmd_line *command)
{
	t_cmd_line	*cur;
	t_cmd_line	*next;

	cur = command;
	while (cur != NULL)
	{
		next = cur->next;
		ft_free_cmd(cur);
		cur = next;
	}
}

void	ft_free_data(t_data *data)
{
	if (data)
	{
		if (data->t)
			ft_free_tokens(data->t);
		if (data->cmd_list)
			ft_free_commands(data->cmd_list);
	}
    free(data);
}
