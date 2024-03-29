/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:29:02 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/22 14:29:11 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void free_strs(char *s1, char *s2)
{
    if (s1)
        free(s1);
    if (s2)
        free(s2);
}

void	ft_free_env_singletone(t_env **env)
{
	t_env	*cur;
	t_env	*prev;

	cur = *env;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		free(prev->str);
		free(prev->key);
		free(prev->value);
		free(prev);
	}
}
void	ft_free_secret_env(t_env **env)
{
	t_env	*cur;
	t_env	*prev;

	cur = *env;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		free(prev->str);
		free(prev->key);
		free(prev->value);
		free(prev);
	}
	free(env);
}
