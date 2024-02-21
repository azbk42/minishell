/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_quot_w_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:53:52 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/21 18:13:54 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static t_token	*alloc_token(const char *str, char **tab)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (ft_free_array(tab), NULL);
	new->type = ARG;
	new->token = ft_strdup(str);
	new->jump = 0;
	new->next = NULL;
	if (new->token == NULL)
	{
		if (new)
			free(new);
		return (NULL);
	}
	return (new);
}

static bool	add_split_to_token(t_token *token, char **tab, int i)
{
	t_token	*new_node;
	t_token	*current;

	current = token;
	while (tab[i])
	{
		new_node = alloc_token(tab[i], tab);
		if (new_node == NULL)
			return (ERROR);
		new_node->next = current->next;
		current->next = new_node;
		current = new_node;
		i++;
	}
	return (OK);
}
static size_t	ft_len_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

static char	*handle_join_and_tab_conditions(char *str_join, char **tab,
		char *new_str)
{
	if (!str_join)
	{
		ft_free_array(tab);
		return (new_str);
	}
	if (!tab[1])
	{
		free(new_str);
		ft_free_array(tab);
		return (str_join);
	}
	return (NULL);
}

char	*init_no_quote_with_dollar(t_token *token, const char *line,
		char *str_expand, int *i)
{
	char	*new_str;
	char	*result;
	char	*str_join;
	char	**tab;

	new_str = exp_with_dollar(line, i);
	if (new_str == NULL)
		return (str_expand);
	tab = ft_split(new_str, ' ');
	token->jump = ft_len_tab(tab) - 1;
	free(new_str);
	new_str = malloc(1);
	new_str[0] = '\0';
	str_join = ft_strjoin(str_expand, tab[0]);
	free(str_expand);
	result = handle_join_and_tab_conditions(str_join, tab, new_str);
	if (result != NULL)
		return (result);
	token->token = str_join;
	add_split_to_token(token, tab, 1);
	ft_free_array(tab);
	return (new_str);
}
