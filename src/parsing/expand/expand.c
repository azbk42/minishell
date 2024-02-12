/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:32:31 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/12 15:23:56 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"


// il reste a chopper la valeur de la variable, et aussi faire la manip quand ya un ? apres le $

void start_expand(t_token *lst_token, char *line, char *str_expand, int *i)
{
	char quote;
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
			if (quote == '\'')
			{
				//printf("je rentre\n");
				str_expand = expand_smpl_quotes(line, str_expand, i);
			}
			if(quote == '"')
			{
				//printf("je rentre pour double quote\n");
				str_expand = expand_dbl_quotes(line, str_expand, i);
			}
			// if (quote == 0)
			// {
			// 	str_expand = expand_no_quotes(line, str_expand, i);
			// }	
		}
	}
	free(line);
	//printf("str_expand = %s\n", str_expand);
	lst_token->token = str_expand;
	printf("lst_token_expand = %s\n", lst_token->token);
	//printf("lst_token->token = %s\n", lst_token->token);
}

void	expand_token(t_token *lst_token, char *line, t_e_token type)
{
	int i;
	char *str_expand;
	char *line_duplicate;

	i = 0;
	line_duplicate = ft_strdup(line);
	free(line);
	line = ft_strtrim(line_duplicate, " ");
	free(line_duplicate);
	str_expand = NULL;
	if (!line || line[0] == '\0')
		return ;
	if (type == LIMITOR)
		return ; // pas besoin d'expand les limitors mais on doit enlever les quotes
	else
		start_expand(lst_token, line, str_expand, &i);
}


void	expand_all_token(t_data *data)
{
	t_cmd_line *command;
	t_token *token_list;

	command = data->cmd_list;
	if (command)
	{
		while (command)
		{
			token_list = command->token_list;
			while (token_list)
			{
				expand_token(token_list ,token_list->token, token_list->type);
				token_list = token_list->next;
			}
			command = command->next;
		}
	}
}
