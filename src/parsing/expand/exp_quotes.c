/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:36:33 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/09 19:25:50 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*expand_smpl_quotes(char *line, char *str_expand, int *i)
{
	char	*str;
	char	*new_str;
	int		j;

	j = *i;
	new_str = NULL;
	while (line && line[*i] && line[*i] != '\'')
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
char *exp_without_dollar(char *line, char *str_expand, int *i)
{
	char *str;
	char *new_str;
	int j;

	j = *i;
	new_str = NULL;
	while (line && line[*i] && line[*i] != '$')
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

int	len_var(char *word)
{
	int	len;

	len = 0;
	while (word[len] && word[len] != '_' && ft_isalnum(word[len]))
		len++;
	while (word[len] == '_')
		len++;
	return (len);
}

// char *delete_var(char *line, int len_variable, int len)
// {

// }

// char *expand_no_quote(char *line, char **env, int *index)
// {

// }

// 	len_variable = find_len_var(&line[len+1], env);
// 	len += len_variable;
// 	new_str = malloc (sizeof(char) * len + 1);
// 	if (!new_str)
// 		return (perror("expand_no_quote"), NULL);
// 	len = -1;
// 	while (line[++len] != '$')
// 		new_str[len] = line[len];
// 	if (len_variable)
// 	{
// 		exp_var = value_variable(&line[len+1], env);
// 		if (!exp_var)
// 			return (perror("expand_no_quote"), NULL);
// 		ft_strlcat(new_str, exp_var, len_variable);
// 		free(exp_var);
// 	}
// 	return (new_str);
// }
