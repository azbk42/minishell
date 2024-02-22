/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:32:31 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/22 16:47:30 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	handle_quotes(char *line, int *i, char *quote)
{
	if ((line[*i] == '"' || line[*i] == '\'') && *quote == 0)
	{
		*quote = line[*i];
		(*i)++;
	}
	else if (line[*i] == *quote && *quote != 0)
	{
		*quote = 0;
		(*i)++;
	}
}

static void	start_expand(t_token *lst_token, char *line, char *str_expand,
		int *i)
{
	char	quote;
	int		jump;

	jump = 0;
	quote = 0;
	printf("token dup = %s\n", line);
	while (line[*i])
	{
		handle_quotes(line, i, &quote);
		if (quote == '\'')
			str_expand = expand_smpl_quotes(line, str_expand, i);
		else if (quote == '"')
			str_expand = expand_dbl_quotes(line, str_expand, i);
		else if (quote == 0)
			str_expand = expand_no_quote(&lst_token, line, str_expand, i);
		jump = lst_token->jump;
		while (jump > 0)
		{
			lst_token = lst_token->next;
			str_expand = lst_token->token;
			jump--;
		}
	}
	free(line);
	lst_token->token = str_expand;
}

static bool	expand_token(t_token *lst_token, char *line, t_e_token type)
{
	int		i;
	char	*str_expand;
	char	*line_duplicate;

	i = 0;
	printf("token = %s\n", lst_token->token);
	line_duplicate = ft_strdup(line);
	free(line);
	str_expand = NULL;
	if (line_duplicate[0] == '\0')
		return (OK);
	if (!line_duplicate)
		return (ft_strdup("\0"));
	if (type == LIMITOR)
	{
		if (init_delete_quote(lst_token, line_duplicate) == ERROR)
			return (ERROR);
	}
	else
	{
		start_expand(lst_token, line_duplicate, str_expand, &i);
	}
	return (OK);
}

static bool	ft_only_space(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] != ' ')
			return (ERROR);
		i++;
	}
	return (OK);
}

bool	expand_all_tokens(t_data *data)
{
	t_cmd_line	*command;
	t_token		*token_list;

	command = data->cmd_list;
	if (command)
	{
		while (command)
		{
			token_list = command->token_list;
			while (token_list)
			{
				if (ft_only_space(token_list->token))
				{
					free(token_list->token);
					token_list->token = ft_strdup("\0");
				}
				else if (expand_token(token_list, token_list->token,
						token_list->type) == ERROR)
					return (ERROR);
				token_list = token_list->next;
			}
			command = command->next;
		}
	}
	return (OK);
}
