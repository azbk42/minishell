/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_quot_w_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:53:52 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/14 12:01:51 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static t_token	*alloc_token(const char *str, char **tab)
{
	t_token	*new;
	char *add_space;

	new = malloc(sizeof(t_token));
	if (!new)
		return (ft_free_array(tab), NULL);
	add_space = (ft_strjoin(str, " "));
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
	t_token	*next;
	t_token	*new;

	 if (!(*token))
        return (ERROR);
	next = (*token)->next;
	while (tab[i])
	{
		new = alloc_token(tab[i], tab);
        printf("new str = %s\n", new->token);
		if (new == NULL)
			return (ERROR);
		new->next = next;
        (*token)->next = new;
		printf("token = %s\n", (*token)->next->token);
		i++;
	}
	ft_free_array(tab);
	return (OK);
}

char	*init_no_quote_with_dollar(t_token **token, const char *line,
		char *str_expand, int *i)
{
	char	*new_str;
	char	*str_join;
	char	**tab;

	new_str = exp_with_dollar(line, i);
	printf("ls = %s\n", new_str);
	if (new_str == NULL)
	{
		free(str_expand);
		return (NULL);
	}
	tab = ft_split(new_str, ' ');
    printf("tab[%d] = %s\n", 0, tab[0]);
    printf("tab[%d] = %s\n", 1, tab[1]);
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
	if (str_expand)
		free(str_expand);
	(*token)->token = str_join;
	if (add_split_to_token(token, tab, 1) == ERROR)
		return (NULL);
	return (str_join);
}
