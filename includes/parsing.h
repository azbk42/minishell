/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:36:51 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/11 12:22:58 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

void	expand_all_token(t_data *data);
void	expand_token(t_token *lst_token, char *line, t_e_token type);
void	delete_quote(char *new_str, char *line, int i, int j);
char	*init_delete_quote(char *line);

/* -------------------------------------------------------------------------- */
/*                                    TOOLS ENV                               */
/* -------------------------------------------------------------------------- */

int		ft_len_env(const char **envp);
bool	is_in_env(const char *line, const char **env);

/* -------------------------------------------------------------------------- */
/*                                    SETUP ENV                               */
/* -------------------------------------------------------------------------- */
bool ft_init_lst_env(const char **envp);
void ft_lst_env(const char *line, t_env **env);

/* -------------------------------------------------------------------------- */
/*                                    SINGLETON                               */
/* -------------------------------------------------------------------------- */
t_env	**ft_singletone_env(void);

/* -------------------------------------------------------------------------- */
/*                                    EXPAND                                  */
/* -------------------------------------------------------------------------- */
char	*expand_smpl_quotes(char *line, char *str_expand, int *i);
char	*expand_no_quote(char *line, char **env, int *index);

char	*exp_without_dollar(char *line, char *str_expand, int *i);

/* -------------------------------------------------------------------------- */
/*                                   A SUPPR                                  */
/* -------------------------------------------------------------------------- */
void	ft_print_env(t_env **env);

#endif