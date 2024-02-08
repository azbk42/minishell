/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:32:31 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/07 17:21:43 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"





// void expand_dbl_quotes(char *line, char *word, char **env)
// {
// 	int i;

// 	i = 0;
// 	while (line[i])
// }

// int len_variable(char *word, char **env, int i)
// {
// 	int i;
// 	int j;
// 	int len;

// 	i = 0;
// 	len = 0;
	
// }

// char *expand_no_quote(char *line, char **env, int *i)
// {
// 	char *str;

// 	str = malloc(sizeof(char) * count_future_len(line, env, i));
// 	if (!str)
// 		return (NULL);

// }



= find_name_var(&line[len]);
    if (word)


char	*check_env_variable(char *line, char **env)
{
	char	prec;
	char **exp_var;
	int		i;
	int j;

	if (count_nb_var_exp(line) == 0)
		return (line);
	exp_var = malloc((count_nb_var_exp(line) + 1) * sizeof(char *));
	//printf("count = %d\n", count_nb_var_exp(line));
	if (!exp_var)
		return (perror("erreur malloc exp_var"), NULL);
	env = NULL;
	j = 0;
	prec = 0;
	i = -1;
	while (line[++i])
	{
		//printf("i = %d and line[i] = %c\n",i, line[i]);
		if ((line[i] == '"' || line[i] == '\'') && prec == 0)
			prec = line[i];
		else if ((line[i] == prec || line[i] == prec) && prec != 0)
			prec = 0;
		if (prec == '\'')
			exp_var[j] = expand_smpl_quotes(&line[i], &i);
		else if (prec == 0)
		 	exp_var[j] = expand_no_quote(&line[i], env, &i);
		// else if (prec == '"')
		// 	exp_var[j] = expand_dbl_quotes(&line[i], env, &i);
		
		j++;
	}
	// exp_var[j] = '\0';
	// free(line);
	// line = join_exp_var(exp_var);
	// free_dbl_char(exp_var);
	return (line);
}

void	expand_all_token(t_token *expd_tok_list, char **env)
{
	t_token	*token_lst;
	char	*line;
	char	*tmp;

	env = NULL;
	token_lst = expd_tok_list;
	while (token_lst)
	{
		line = token_lst->token;
		if (!line || line[0] == '\0')
			return ;
		// retirer les espaces
		tmp = ft_strtrim(line, " ");
		free(line);
		// regarder si la $ existe dans lenv
		// find_word("SLT salut");

		line = check_env_variable("'salut a tous'Yo$USER'bonsoir paris'", env);
		//
		// expand les $ si necessaire
		// supprimer les quotes useless
		line = init_delete_quote(tmp);
		free(tmp);
		token_lst->token = line;
		token_lst = token_lst->next;
	}
}

void	expand_cmd(t_data *data, char **env)
{
	t_cmd_line *current;
	t_token *expd_tok_list;

	current = data->cmd_list;
	if (current)
	{
		while (current)
		{
			expd_tok_list = current->token_list;
			expand_all_token(expd_tok_list, env);
			current = current->next;
		}
	}
}