/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:13:16 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/22 16:51:14 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char *one_dollar(int *i)
{
	char *str;

	str = malloc(2);
	if (str == NULL)
		return (MALLOC_ERROR);
	str[0] = '$';
	str[1] = '\0';
	(*i)++;
	return (str);
}

// char	*new_token_env(t_token **stc, char **split, int i)
// {
// 	t_token	*next;
// 	t_token	*new;

// 	if ((*stc))
// 		next = (*stc)->next;
// 	while (split[i])
// 	{
// 		new = malloc(sizeof(t_token));
// 		if (new == NULL)
// 			return (free_split_ret_str(split, NULL));
// 		init_token(new);
// 		new->type = ARG;
// 		new->str = ft_strdup(split[i]);
// 		if (new->str == NULL)
// 			if (new)
// 				return (free_split_token(split, new));
// 		if ((*stc))
// 			new->next = next;
// 		(*stc)->next = new;
// 		(*stc) = (*stc)->next;
// 		i++;
// 	}
// 	free_split(split);
// 	return (new->str);
// }



char *init_exp_with_dollar(const char *line, char *str_expand, int *i)
{
	char *str_exp;
	char *str_join;
	
	str_exp = exp_with_dollar(line, i);
	str_join = ft_strjoin(str_expand, str_exp);
	free(str_exp);
	free(str_expand);
	return (str_join);
}

char *exp_with_dollar(const char *line, int *i)
{
	char *new_str;
	char *variable;
	size_t len_var;

	variable = NULL;
	new_str = NULL;
	len_var = find_len_var(&line[*i]);
	if (len_var == 0)
		return (one_dollar(i));
	// if (len_var == 1 && line[*i + 1] == '?')
	// {
	// 	new_str = ft_itoa(g_global->status);
	// 	if (new_str == NULL)
	// 		return (MALLOC_ERROR);
	// }
	variable = malloc(sizeof(char) * (len_var + 1));
	if (variable == NULL)
		return (MALLOC_ERROR);
	variable = ft_strncpy(variable, &line[*i+1], len_var);
	(*i) += len_var + 1;
	new_str = get_value_env(variable);
	free(variable);
	return (new_str);
}
char *exp_without_dollar(const char *line, char *str_expand, int *i)
{
	char *str;
	char *new_str;
	int j;

	j = *i;
	new_str = NULL;
	while (line && line[*i] && line[*i] != '$' && line[*i] != '"')
		(*i)++;
	str = malloc(sizeof(char) * ((*i) - j + 1));
	if (str == NULL)
	{
		if (str_expand)
			free(str_expand);
		return (MALLOC_ERROR);
	}
	str = ft_strncpy(str, &line[j], (*i) - j);
	new_str = ft_strjoin(str_expand, str);
	free(str);
	free(str_expand);
	return (new_str);
}
char	*exp_no_quote_no_dol(const char *line, char *str_expand, int *i)
{
	char	*str;
	char	*new_str;
	int		j;

	j = *i;
	new_str = NULL;
	while (line && line[*i] && line[*i] != '$' && line[*i] != '"'
		&& line[*i] != '\'')
		(*i)++;
	str = malloc(sizeof(char) * ((*i) - j + 1));
	if (str == NULL)
	{
		if (str_expand)
			free(str_expand);
		return (MALLOC_ERROR);
	}
	str = ft_strncpy(str, &line[j], (*i) - j);
	new_str = ft_strjoin(str_expand, str);
	free(str);
	free(str_expand);
	return (new_str);
}
