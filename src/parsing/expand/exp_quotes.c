/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:36:33 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/07 17:23:46 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"


char *expand_smpl_quotes(char *line, int *index)
{
	int len;
	char *new_str;
	int i;

	len = 0;
	while (line[++len] != '\'')
		;
	new_str = malloc(sizeof(char) * len + 3);
	if (!new_str)
		return (perror("error exp_simple_quote"), NULL);
	if (len == 0)
	{
		new_str[0] = '\'';
		new_str[1] = '\'';
		new_str[2] = '\0';
	}
	i  = -1;
	while (++i < len)
	{
		new_str[i] = line[i];
		(*index) ++;
	}
	(*index) --;
	new_str[len] = '\'';
	new_str[len+1] = '\0';
	printf("simple quote = %s\n", new_str);
	return (new_str);	
}


int len_var(char *word)
{
    int len;

    len = 0;
    while (word[len] && word[len] != '_' && ft_isalnum(word[len]))
		len++;
    while (word[len] == '_')
        len++;
    return (len);
}

char *delete_var(char *line, int len_variable, int len)
{
    char *new_str;
    int i;
    
    i = -1;
    new_str = malloc(len + 1);
    if (!new_str)
        return (NULL);
    while (line[++i] && line[i] != '$')
    {
        new_str()
    }
        
}


char *expand_no_quote(char *line, char **env, int *index)
{
	int len;
	int len_variable;
	int i;
    char *word;
    char *new_str;

	len = 0;
	while(line[len] != '$')
		len++;
    len_variable = len_var(&line[len]);
    word = find_name_var(&line[len]);
    len += len_variable;
    while (!ft_isalnum(line[len]))
        len ++;
    (* index)++;
    if (!var_exist(word, env))
        new_str = delete_var(line, len_variable, len);

}








        
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
