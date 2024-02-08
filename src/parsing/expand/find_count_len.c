/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_count_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:11:07 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/07 13:03:10 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int len_env(char **envp)
{
    int i;
    
    i = 0;
    if (!envp)
        return (print_error("len_envp don't exist"), -1);
    while (envp[i])
        i++;
    return (i);
}


char **init_env(char **envp)
{
    int len;
    char **env;
    int i;

    i = -1;
    len = len_env(envp);
    if (len == -1)
        return (NULL);
    env = malloc(sizeof(char *) * (len + 1));
    if (!env)
        return (perror("env alloc failed"), NULL);
    while (envp[++i])
    {
        env[i] = ft_strdup(envp[i]);
        if (!env[i])
            return (perror("env[i] alloc failed"), NULL);
    }
    return (env);
}

bool is_in_env(char *line, char **env)
{
	int i;
	int j;

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
char	*find_name_var(char *word)
{
	char	*variable;
	int		len;

	variable = 0;
	len = 0;
	while (word[len] && word[len] != '_' && ft_isalnum(word[len]))
		len++;
	if (len == 0)
	{
		variable = malloc(2);
		if (!variable)
			return (NULL);
		variable[0] = '$';
		variable[1] = '\0';
		return (variable);
	}
	variable = malloc(len + 1);
	if (!variable)
		return (NULL);
	ft_strlcpy(variable, word, len+1);
	return (variable);
}

int count_nb_var_exp(char *line)
{
	int i;
	char prec;
	int count;

	count = 0;
	prec = 0;
	i = -1;
	if (!line)
		return (-1);
	while (line[++i])
	{
		if ((line[i] == '"' || line[i] == '\'') && prec == 0)
			prec = line[i];
		else if ((line[i] == prec || line[i] == prec) && prec != 0)
			prec = 0;
		if ((line[i] == '$' && prec == 0) || (line[i] == '$' && prec == '"'))
			count ++;
	}
	return (count);
}
