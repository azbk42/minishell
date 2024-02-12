/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:36:51 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/12 15:28:25 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H



void	expand_all_token(t_data *data);
void	expand_token(t_token *lst_token, char *line, t_e_token type);
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
char	*expand_no_quote(const char *line, char **env, int *index);
char	*expand_dbl_quotes(const char *line, char *str_expand, int *i);

char	*init_exp_with_dollar(const char *line, char *str_expand, int *i);
char	*exp_without_dollar(const char *line, char *str_expand, int *i);
char	*exp_with_dollar(const char *line, int *i);

/* -------------------------------------------------------------------------- */
/*                                  UTILS                                     */
/* -------------------------------------------------------------------------- */
size_t find_len_var(const char *line);
char	*get_value_env(const char *variable);
/* -------------------------------------------------------------------------- */
/*                                   A SUPPR                                  */
/* -------------------------------------------------------------------------- */
void	ft_print_env(t_env **env);

#endif