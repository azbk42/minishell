/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:20:25 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/21 18:14:13 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	*ft_dup_key(const char *line)
{
	int		i;
	char	*key;

	i = 0;
	while (line && line[i] && line[i] != '=')
	{
		i++;
	}
	if (i == 0)
		return (VAR_EMPTY);
	key = malloc(sizeof(char) * (i + 1));
	if (key == NULL)
		return (MALLOC_ERROR);
	ft_strncpy(key, line, i);
	return (key);
}

static char	*ft_dup_value(const char *line)
{
	int		i;
	char	*value;

	i = 0;
	while (line && line[i] && line[i] != '=')
		i++;
	if (line[i] == '=')
		i++;
	value = ft_strdup(&line[i]);
	if (value == NULL)
		return (MALLOC_ERROR);
	return (value);
}

bool	ft_lst_env(const char *line, t_env **env)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (new == NULL)
		return (ERROR);
	new->str = ft_strdup(line);
	new->key = ft_dup_key(line);
	new->value = ft_dup_value(line);
	new->next = *env;
	*env = new;
	if (!new->str || !new->key || !new->value)
		return (ERROR);
	return (OK);
}
