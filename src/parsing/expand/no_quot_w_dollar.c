/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_quot_w_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:53:52 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/20 16:27:52 by emauduit         ###   ########.fr       */
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
    new->next = NULL;
	if (new->token == NULL)
	{
		ft_free_array(tab);
		if (new)
		{
			free(new->token);
		}
		return (NULL);
	}
	return (new);
}

static bool	add_split_to_token(t_token **token, char **tab, int i)
{
	t_token	*new_node;

	
	t_token *current = *token;
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
	ft_free_array(tab);
	return (OK);
}
static size_t ft_len_tab(char **tab)
{
	size_t i;

	i = 0;
	while(tab[i])
	{
		i++;
	}
	return (i);
}

char	*init_no_quote_with_dollar(t_token **token, const char *line,
		char *str_expand, int *i)
{
	char	*new_str;
	char	*str_join;
	char	**tab;

	new_str = exp_with_dollar(line, i);
	printf("new str = %s\n", new_str);
	if (new_str == NULL)
	{
		return (str_expand);
	}
	tab = ft_split(new_str, ' ');
	(*token)->jump = ft_len_tab(tab) - 1;
	printf("len tab = %lu\n", (ft_len_tab(tab) - 1));
	free(new_str);
	if (tab == NULL)
		return (MALLOC_ERROR);
	str_join = ft_strjoin(str_expand, tab[0]);
	if (!str_join)
	{
		if (str_expand)
			free(str_expand);
		return (ft_free_array(tab), NULL);
	}
	(*token)->token = str_join;
	if (add_split_to_token(token, tab, 1) == ERROR)
		return (NULL);
	return (NULL);
}
