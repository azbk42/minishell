/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:32:31 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/21 18:09:42 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	*exp_according_quotes(t_token *tok, const char *line,
		char *str_expand, int *i, char quote)
{
	char	*new_str;

	new_str = NULL;
	if (quote == '\'')
		new_str = expand_smpl_quotes(line, str_expand, i);
	else if (quote == '"')
		new_str = expand_dbl_quotes(line, str_expand, i);
	else if (quote == 0)
		new_str = expand_no_quote(tok, line, str_expand, i);
	return (new_str);
}



static void	start_expand(t_token *lst_token, char *line, int *i)
{
	char	*str_expand;
	char	quote;

	str_expand = NULL;
	quote = 0;
	while (line[*i])
	{
		handle_quotes(line, i, &quote);
		str_expand = exp_according_quotes(lst_token, line, str_expand, i,
				quote);
		lst_token = jump_function(lst_token);
		if (str_expand[0] == '\0')
		{
			free(str_expand);
			return ;
		}
		if (lst_token->jump > 0)
			str_expand = lst_token->token;
	}
	lst_token->token = str_expand;
}

static bool	expand_token(t_token *lst_token, char *line, t_e_token type)
{
	int		i;
	char	*line_duplicate;

	i = 0;
	if (!line)
		return (ERROR);
	line_duplicate = ft_strtrim(line, " ");
	if (!line_duplicate)
		return (ERROR);
	free(lst_token->token);
	if (type == LIMITOR)
	{
		if (init_delete_quote(lst_token, line_duplicate) == ERROR)
		{
			free(line_duplicate);
			return (ERROR);
		}
	}
	else
	{
		start_expand(lst_token, line_duplicate, &i);
	}
	free(line_duplicate);
	return (OK);
}

static bool ft_only_space(char *line)
{
	int i;
	
	i = 0;
	while (line[i])
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
