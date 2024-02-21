/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:36:51 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/21 16:00:18 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

bool	expand_all_tokens(t_data *data);
/* -------------------------------------------------------------------------- */
/*                                    TOOLS ENV                               */
/* -------------------------------------------------------------------------- */

size_t	ft_len_env(const char **envp);
bool	is_in_env(const char *line, const char **env);

/* -------------------------------------------------------------------------- */
/*                                    SETUP ENV                               */
/* -------------------------------------------------------------------------- */
bool	ft_init_lst_env(const char **envp);
bool	ft_lst_env(const char *line, t_env **env);

/* -------------------------------------------------------------------------- */
/*                                    EXPAND                                  */
/* -------------------------------------------------------------------------- */
char	*expand_smpl_quotes(const char *line, char *str_expand, int *i);
char	*expand_no_quote(t_token *tok, const char *line, char *str_expand, int *i);
char	*expand_dbl_quotes(const char *line, char *str_expand, int *i);
char	*init_exp_with_dollar(const char *line, char *str_expand,
			int *i);

void	handle_quotes(char *line, int *i, char *quote);
t_token	*jump_function(t_token *lst_token);

char	*exp_without_dollar(const char *line, char *str_expand, int *i);
char	*exp_with_dollar(const char *line, int *i);
char	*exp_no_quote_no_dol(const char *line, char *str_expand, int *i);
char *init_no_quote_with_dollar(t_token *token ,const char *line, char *str_expand, int *i);
char *init_no_quote_with_dollar(t_token *token ,const char *line, char *str_expand, int *i);


/* -------------------------------------------------------------------------- */
/*                                  DEL QUOTES                                     */
/* -------------------------------------------------------------------------- */

void	delete_quote(char *new_str, char *line, int i, int j);
bool	init_delete_quote(t_token *lst_token, char *line);

/* -------------------------------------------------------------------------- */
/*                                  UTILS                                     */
/* -------------------------------------------------------------------------- */
size_t	find_len_var(const char *line);
char	*get_value_env(const char *variable);
/* -------------------------------------------------------------------------- */
/*                                   A SUPPR                                  */
/* -------------------------------------------------------------------------- */
void	ft_print_env(t_env **env);

#endif