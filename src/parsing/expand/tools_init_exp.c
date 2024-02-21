/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_init_exp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:59:29 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/21 16:00:27 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_quotes(char *line, int *i, char *quote)
{
	if ((line[*i] == '"' || line[*i] == '\'') && *quote == 0)
	{
		*quote = line[*i];
		(*i)++;
	}
	if (line[*i] == *quote && *quote != 0)
	{
		*quote = 0;
		(*i)++;
	}
}

t_token	*jump_function(t_token *lst_token)
{
	int	jump;

	jump = lst_token->jump;
	while (jump > 0)
	{
		if (lst_token->next != NULL)
		{
			lst_token = lst_token->next;
		}
		jump--;
	}
	return (lst_token);
}
