/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_quot_w_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:53:52 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/26 13:30:19 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static t_token	*alloc_token(const char *str)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (MALLOC_ERROR);
	new->type = ARG;
	new->token = ft_strdup(str);
	new->next = NULL;
	if (new->token == NULL)
	{
		return (MALLOC_ERROR);
	}
	return (new);
}

static char	*add_split_to_token(t_token **token, char **tab, int i)
{
	t_token	*new_node;
	t_token	*next_node;

	next_node = (*token)->next;
	while (tab[i])
	{
		new_node = alloc_token(tab[i]);
		if (new_node == NULL || new_node->token == NULL)
		{
			if (new_node->token)
				free(new_node->token);
			ft_free_array(tab);
			return (MALLOC_ERROR);
		}
		if (*token)
			new_node->next = next_node;
		(*token)->next = new_node;
		(*token) = (*token)->next;
		i++;
	}
	ft_free_array(tab);
	return (new_node->token);
}

static char	*free_str_expand(char *str_expand)
{
	if (str_expand)
		free(str_expand);
	return (MALLOC_ERROR);
}

char	*init_no_quote_with_dollar(t_token **token, const char *line,
		char *str_expand, int *i)
{
	char	*new_str;
	char	*str_join;
	char	**tab;

	new_str = exp_with_dollar(line, i);
	if (new_str == NULL)
		return (free_str_expand(str_expand));
	tab = ft_split(new_str, ' ');
	free(new_str);
	if (tab == NULL)
		return (free_str_expand(str_expand));
	str_join = ft_strjoin(str_expand, tab[0]);
	if (str_join == NULL)
		str_join = ft_strdup("\0");
	free(str_expand);
	if (!tab[0] || !tab[1])
	{
		ft_free_array(tab);
		return (str_join);
	}
	(*token)->token = str_join;
	return (add_split_to_token(token, tab, 1));
}
