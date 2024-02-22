/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:54:34 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/20 16:25:55 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	delete_quote(char *new_str, char *line, int i, int j)
{
	char	flag;

	flag = 0;
	while (line[++i] != '\0')
	{
		if ((line[i] == '"' || line[i] == '\'') && (flag == 0
				|| flag == line[i]))
		{
			if (flag == line[i])
				flag = 0;
			else
				flag = line[i];
		}
		else if (flag != 0 || (line[i] != '"' && line[i] != '\''))
			new_str[j++] = line[i];
	}
	new_str[j] = '\0';
}

bool	init_delete_quote(t_token *lst_token, char *line)
{
	char	*new_str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	new_str = malloc(ft_strlen(line) + 1);
	if (!new_str)
		return (ERROR);
	delete_quote(new_str, line, i, j);
	free(line);
	lst_token->token = new_str;
	return (OK);
}
