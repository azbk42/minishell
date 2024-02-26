/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_count_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:11:07 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/26 13:32:32 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

size_t	find_len_var(const char *line)
{
	size_t	len_var;

	len_var = 0;
	if (line[0] == '$')
		line++;
	if (line[0] == '?')
	{
		len_var++;
		return (len_var);
	}
	while (line[len_var] && (ft_isalnum(line[len_var]) == 1
			|| line[len_var] == '_'))
	{
		len_var++;
	}
	return (len_var);
}

size_t	ft_len_env(const char **envp)
{
	size_t	i;

	i = 0;
	if (!envp)
		return (0);
	while (envp[i])
		i++;
	return (i);
}

char	*get_value_env(const char *variable)
{
	t_env	**env;
	t_env	*cur;
	char	*var_add_equal;
	char	*new_str;

	new_str = NULL;
	env = ft_singletone_env();
	var_add_equal = ft_strjoin(variable, "=");
	if (var_add_equal == NULL)
		return (MALLOC_ERROR);
	cur = *env;
	while (cur)
	{
		if (ft_strncmp(var_add_equal, cur->str, (ft_strlen(variable) + 1)) == 0)
		{
			new_str = ft_strdup(cur->value);
			if (new_str == NULL)
				return (free(var_add_equal), MALLOC_ERROR);
		}
		cur = cur->next;
	}
	free(var_add_equal);
	return (new_str);
}

bool	is_in_env(const char *line, const char **env)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		if (env[i][j] == line[j])
		{
			while (env[i][j] == line[j] && env[i][j] != '=')
				j++;
			if (line[j] == '\0')
				return (true);
		}
		i++;
	}
	return (false);
}
