/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_count_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:11:07 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/12 10:27:04 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

size_t ft_len_env(const char **envp)
{
    size_t i;
    
    i = 0;
    if (!envp)
        return (0);
    while (envp[i])
        i++;
    return (i);
}

bool is_in_env(const char *line, const char **env)
{
	size_t i;
	size_t j;

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
