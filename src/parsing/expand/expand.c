/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:32:31 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/21 13:46:55 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	*exp_according_quotes(t_token *tok, const char *line,
		char *str_expand, int *i, char quote)
{
	char *new_str;
	
	new_str = NULL;
	if (quote == '\'')
		new_str = expand_smpl_quotes(line, str_expand, i);
	else if (quote == '"')
		new_str = expand_dbl_quotes(line, str_expand, i);
	else if (quote == 0)
		new_str = expand_no_quote(tok, line, str_expand, i);
	if (str_expand)
	{
		free(str_expand);
		str_expand = NULL;
	}
	return (new_str);
}


static void	start_expand(t_token *lst_token, char *line, char *str_expand,
		int *i)
{
	char	quote;
	int		jump;

	quote = 0;
	while (line[*i])
	{
		if ((line[*i] == '"' || line[*i] == '\'') && quote == 0)
		{
			quote = line[*i];
			(*i)++;
		}
		if (line[*i] == quote && quote != 0)
		{
			quote = 0;
			(*i)++;
		}
		str_expand = exp_according_quotes(lst_token, line, str_expand, i,
				quote);
		jump = lst_token->jump;
		printf("str_expand = %s\n", str_expand);
		while (jump > 0)
		{
			if (lst_token->next != NULL)
			{
				lst_token = lst_token->next;
				if (str_expand)
				{
					free(str_expand);
					str_expand = NULL;
				}
				str_expand = lst_token->token;
				jump--;
			}
			else
			{
				break ;
			}
		}
	}
	if (str_expand)
	{
		if (lst_token->token)
			free(lst_token->token);
		lst_token->token = str_expand;
	}
}

static bool	expand_token(t_token *lst_token, char *line, t_e_token type)
{
	int		i;
	char	*str_expand;
	char	*line_duplicate;

	i = 0;
	str_expand = NULL;
	if (!line)
		return (ERROR);
	line_duplicate = ft_strdup(line);
	line = ft_strtrim(line_duplicate, " ");
	if (line_duplicate)
		free(line_duplicate);
	if (!line)
		return (ERROR);
	if (type == LIMITOR)
	{
		if (init_delete_quote(lst_token, line) == ERROR)
		{
			free(line);
			return (ERROR);
		}
	}
	else
	{
		start_expand(lst_token, line, str_expand, &i);
	}
	free(line);
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
				if (expand_token(token_list, token_list->token,
						token_list->type) == ERROR)
					return (ERROR);
				token_list = token_list->next;
			}
			command = command->next;
		}
	}
	return (OK);
}
