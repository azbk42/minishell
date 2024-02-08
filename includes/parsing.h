/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:36:51 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/07 16:38:34 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

void	expand_cmd(t_data *data,char **env);
void expand_all_token(t_token *expd_tok_list,char **env);
void delete_quote(char *new_str, char *line, int i, int j);
char	*init_delete_quote(char *line);


/* -------------------------------------------------------------------------- */
/*                                    SETUP ENV                               */
/* -------------------------------------------------------------------------- */
char **init_env(char **envp);
// check and compare str with all str variable in the env until find a '='
bool is_in_env(char *line, char **env);
// check if we should expand the $VAR depend on the type of quote and type of the token
char *check_env_variable(char *line, char **env);
// look for the name of the variable after find a $ in double quote or without 
char	*find_name_var(char *word);
// count the number of variable we will expand before do it, to malloc a char ** with the number of var to expand we found
int count_nb_var_exp(char *line);

/* -------------------------------------------------------------------------- */
/*                                    EXPAND                                  */
/* -------------------------------------------------------------------------- */
// expand beetween ' ' and move index to the end of the last '
char *expand_smpl_quotes(char *line, int *index);
//
char *expand_no_quote(char *line, char **env, int *index);

#endif