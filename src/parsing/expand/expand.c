/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:32:31 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/04 19:16:35 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void delete_quote(char *new_str, char *line, int i, int j)
{
    char flag;

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

char	*init_delete_quote(char *line)
{
	char	*new_str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	new_str = malloc(ft_strlen(line) + 1);
	if (!new_str)
		return (NULL);
	delete_quote(new_str, line, i, j);
	return (new_str);
}

void	expand_all_token(t_token *expd_tok_list)
{
	t_token	*token_lst;
	char	*line;
	char	*tmp;

	token_lst = expd_tok_list;
	while (token_lst)
	{
		line = token_lst->token;
		if (!line || line[0] == '\0')
			return ;
		// retirer les espaces
		tmp = ft_strtrim(line, " ");
		free(line);
		// expand les $ si necessaire
        
		// supprimer les quotes useless
		printf("line before = %s\n", tmp);
		line = init_delete_quote(tmp);
        free(tmp);
		printf("line after = %s\n", line);
		token_lst->token = line;
		token_lst = token_lst->next;
	}
}

void	expand_cmd(t_data *data, char **env)
{
	t_cmd_line *current;
	t_token *expd_tok_list;
    
    env = NULL;
	current = data->cmd_list;
	if (current)
	{
		while (current)
		{
			expd_tok_list = current->token_list;
			expand_all_token(expd_tok_list);
			current = current->next;
		}
	}
}