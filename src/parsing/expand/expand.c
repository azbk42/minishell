/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:32:31 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/26 15:05:41 by emauduit         ###   ########.fr       */
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

static bool	start_expand(t_token **lst_token, char *line, char *str_expand,
		int *i)
{
	char	quote;

	quote = 0;
	while (line[*i])
	{
		handle_quotes(line, i, &quote);
		if (quote == '\'')
			str_expand = expand_smpl_quotes(line, str_expand, i);
		else if (quote == '"')
			str_expand = expand_dbl_quotes(line, str_expand, i);
		else if (quote == 0)
			str_expand = expand_no_quote(lst_token, line, str_expand, i);
		if (str_expand == NULL)
			return (ERROR);
	}
	free(line);
	(*lst_token)->token = str_expand;
	return (OK);
}

static bool	expand_token(t_token **lst_token, char *line, t_e_token type)
{
	int		i;
	char	*str_expand;
	char	*new_str;

	i = 0;
	str_expand = NULL;
	if (type == LIMITOR)
	{
		if (init_delete_quote(*lst_token, line) == ERROR)
			return (ERROR);
	}
	new_str = ft_strdup(line);
	if (new_str == NULL)
		return (ERROR);
	free(line);
	(*lst_token)->token = NULL;
	if (start_expand(lst_token, new_str, str_expand, &i) == ERROR)
		return (ERROR);
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
				if (expand_token(&token_list, token_list->token,
						token_list->type) == ERROR)
					return (ERROR);
				token_list = token_list->next;
			}
			command = command->next;
		}
	}
	if (prepare_execution(data) == ERROR)
		return (ERROR);
	return (OK);
}
