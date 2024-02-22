/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:20:25 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/22 14:28:30 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env **dup_secret_env(t_env **env)
{
	t_env **secret_env;
	t_env *current;

	current = *env;
	secret_env = malloc(sizeof(t_env*));
	*secret_env = NULL;
	while (current)
	{
		ft_lst_env(current->str, secret_env);
		current = current->next;
	}
	return (secret_env);
}

bool	ft_init_baby_env(t_env **env)
{
	char	*str;

	str = ft_strjoin("PWD=", getcwd(NULL, 0));
	if (str == NULL)
	{
		return (ERROR);
	}
	if (ft_lst_env(str, env) == 0)
	{
		free(str);
		return (ERROR);
	}
	if (ft_init_shlvl(env) == 0)
	{
		return (ERROR);
	}
	return (OK);
}

bool	ft_init_lst_env(const char **envp)
{
	int		len;
	t_env	**env;

	env = ft_singletone_env();
	len = ft_len_env(envp);
	if (len == 0)
	{
		if (ft_init_baby_env(env) == false)
		{
			ft_free_env_singletone(env);
			return (ERROR);
		}
	}
	len--;
	while (len >= 0)
	{
		ft_lst_env(envp[len], env);
		if ((*env)->str == NULL || (*env)->key == NULL)
			return (ERROR);
		len--;
	}
	return (OK);
}
