/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:32:31 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/12 11:58:24 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"


size_t find_len_var(char *line)
{
	size_t len_var;

	len_var = 0;
	if (line[0] == '$')
		line++;
	if (line[1] == '?')
	{
		len_var++;
		return (len_var);		
	}
	while (line[len_var] && (ft_isalnum(line[len_var]) == 1 || line[len_var] == '_'))
	{
		len_var++;
	}
	printf("len var = %ld\n", len_var);
	return (len_var);
}
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

// char *get_value_env(char *variable)
// {
// 	int i;
// 	char *value;
// 	char **env;

// 	i = 0;
// 	value = NULL;
// 	env = g_global->env;
// 	while (env[i])
// 	{
// 		if (ft_strncmp(env[i], variable, ft_strlen(variable)) == 0)
// 		{
// 			value = ft_strdup(&env[i][ft_strlen(variable) + 1]);
// 			if (value == NULL)
// 				return (MALLOC_ERROR);
// 			return (value);
// 		}
// 		i++;
// 	}
// 	return (VAR_EMPTY);
// }

// il reste a chopper la valeur de la variable, et aussi faire la manip quand ya un ? apres le $
char *exp_with_dollar(char *line, int *i)
{
	char *new_str;
	char *variable;
	size_t len_var;

	variable = NULL;
	new_str = NULL;
	len_var = find_len_var(&line[*i]);
	printf("line[*i] = %c\n", line[*i]);
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
	printf("variable = %s\n", variable);
	//new_str = get_value_env(variable);
	new_str = NULL;
	free(variable);
	return (new_str);
}
char *init_exp_with_dollar(char *line, char *str_expand, int *i)
{
	char *str_exp;
	char *str_join;
	
	str_exp = exp_with_dollar(line, i);
	
	str_join = ft_strjoin(str_expand, str_exp);
	free(str_exp);
	free(str_expand);
	return (str_join);
}

char *expand_dbl_quotes(char *line, char *str_expand, int *i)
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

void start_expand(t_token *lst_token, char *line, char *str_expand, int *i)
{
	char quote;
	printf("line = %s\n", line);
	quote = 0;
	while (line[*i])
	{
		if ((line[*i] == '"' || line[*i] == '\'') && quote == 0)
		{
			quote = line[*i];
			(*i)++;
		}
		if (line[*i] == quote && quote != 0)
		{
			quote = 0;
			(*i)++;
		}
		else
		{
			if (quote == '\'')
			{
				printf("je rentre\n");
				str_expand = expand_smpl_quotes(line, str_expand, i);
			}
			if(quote == '"')
			{
				printf("je rentre pour double quote\n");
				str_expand = expand_dbl_quotes(line, str_expand, i);
			}
			// if (quote == 0)
			// {
			// 	str_expand = expand_no_quotes(line, str_expand, i);
			// }	
		}
		printf("str_expand = %s\n", str_expand);
		
	}
	free(line);
	//printf("str_expand = %s\n", str_expand);
	lst_token->token = str_expand;
	//printf("lst_token->token = %s\n", lst_token->token);
}



void	expand_token(t_token *lst_token, char *line, t_e_token type)
{
	int i;
	char *str_expand;
	char *line_duplicate;

	i = 0;
	line_duplicate = ft_strdup(line);
	free(line);
	line = ft_strtrim(line_duplicate, " ");
	free(line_duplicate);
	str_expand = NULL;
	if (!line || line[0] == '\0')
		return ;
	if (type == LIMITOR)
		return ; // pas besoin d'expand les limitors mais on doit enlever les quotes
	else
		start_expand(lst_token, line, str_expand, &i);
}



void	expand_all_token(t_data *data)
{
	t_cmd_line *command;
	t_token *token_list;

	command = data->cmd_list;
	if (command)
	{
		while (command)
		{
			token_list = command->token_list;
			while (token_list)
			{
				expand_token(token_list ,token_list->token, token_list->type);
				token_list = token_list->next;
			}
			command = command->next;
		}
	}
}