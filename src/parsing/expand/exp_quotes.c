/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:36:33 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/26 13:04:33 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*expand_smpl_quotes(const char *line, char *str_expand, int *i)
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

char	*expand_dbl_quotes(const char *line, char *str_expand, int *i)
{
	while (line && line[*i] && line[*i] != '"')
	{
		if (line[*i] != '$')
		{
			str_expand = exp_without_dollar(line, str_expand, i);
		}
		else
		{
			str_expand = init_exp_with_dollar(line, str_expand, i);
		}
		if (str_expand == NULL)
			return (MALLOC_ERROR);
	}
	return (str_expand);
}

char	*expand_no_quote(t_token **tok, const char *line, char *str_expand,
		int *i)
{
	while (line && line[*i] && line[*i] != '"' && line[*i] != '\'')
	{
		if (line[*i] != '$')
		{
			str_expand = exp_no_quote_no_dol(line, str_expand, i);
		}
		else
		{
			str_expand = init_no_quote_with_dollar(tok, line, str_expand, i);
		}
		if (str_expand == NULL)
			return (MALLOC_ERROR);
	}
	return (str_expand);
}
