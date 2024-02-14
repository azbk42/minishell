/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:32:31 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/14 15:04:52 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	*exp_according_quotes(t_token **tok, const char *line,
		char *str_expand, int *i, char quote)
{
	if (quote == '\'')
		str_expand = expand_smpl_quotes(line, str_expand, i);
	else if (quote == '"')
		str_expand = expand_dbl_quotes(line, str_expand, i);
	else if (quote == 0)
		str_expand = expand_no_quote(tok, line, str_expand, i);
	return (str_expand);
}
static void	start_expand(t_token **lst_token, char *line, char *str_expand,
		int *i)
{
	char	quote;

	printf("token before = %s\n", line);
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
		else
		{
			str_expand = exp_according_quotes(lst_token, line, str_expand, i,
					quote);
			if ((*lst_token)->jump > 0)
			{
				int i = 2;
				(*lst_token)->token = str_expand;
				while (i-- > 0)
				{
					(*lst_token) = (*lst_token)->next; 
				}
				str_expand = (*lst_token)->token;
			}
		}
		printf("str_expand = %s\n", str_expand);
	}
	free(line);
	(*lst_token)->token = str_expand;
}

static bool	expand_token(t_token **lst_token, char *line, t_e_token type)
{
	int		i;
	char	*str_expand;
	char	*line_duplicate;

	i = 0;
	line_duplicate = ft_strdup(line);
	if (line)
		free(line);
	line = ft_strtrim(line_duplicate, " ");
	if (line_duplicate)
		free(line_duplicate);
	str_expand = NULL;
	if (line[0] == '\0')
		return (OK);
	if (!line)
		return (ERROR);
	if (type == LIMITOR)
	{
		if (init_delete_quote(lst_token, line) == ERROR)
			return (ERROR);
	}
	else
	{
		str_expand = malloc(1);
		if (str_expand == NULL)
			return (ERROR);
		str_expand[0] = '\0';
		start_expand(lst_token, line, str_expand, &i);
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
				if (expand_token(&token_list, token_list->token,
						token_list->type) == ERROR)
					return (ERROR);
				token_list = token_list->next;
			}
			command = command->next;
		}
	}
	return (OK);
}
