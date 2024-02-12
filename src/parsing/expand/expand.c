/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:32:31 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/12 17:01:08 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char *exp_according_quotes(const char *line, char *str_expand, int *i, char quote)
{
	if (quote == '\'')
		str_expand = expand_smpl_quotes(line, str_expand, i);
	else if (quote == '"')
		str_expand = expand_dbl_quotes(line, str_expand, i);
	else if (quote == 0)
		str_expand = expand_no_quote(line, str_expand, i);
	return (str_expand);
}
static void	start_expand(t_token *lst_token, char *line, char *str_expand, int *i)
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
			str_expand = exp_according_quotes(line, str_expand, i, quote);
	}
	free(line);
	lst_token->token = str_expand;
	printf("lst_token_expand = %s\n", lst_token->token);
}

static void	expand_token(t_token *lst_token, char *line, t_e_token type)
{
	int		i;
	char	*str_expand;
	char	*line_duplicate;

	i = 0;
	line_duplicate = ft_strdup(line);
	free(line);
	line = ft_strtrim(line_duplicate, " ");
	free(line_duplicate);
	str_expand = NULL;
	if (!line || line[0] == '\0')
		return ;
	if (type == LIMITOR)
	{
		init_delete_quote(lst_token, line);	
	}
	else
		start_expand(lst_token, line, str_expand, &i);
}

void	expand_all_tokens(t_data *data)
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
				expand_token(token_list, token_list->token, token_list->type);
				token_list = token_list->next;
			}
			command = command->next;
		}
	}
}
