/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:36:51 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/04 19:16:41 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

void	expand_cmd(t_data *data, char **env);
void expand_all_token(t_token *expd_tok_list);
void delete_quote(char *new_str, char *line, int i, int j);
char	*init_delete_quote(char *line);

/* -------------------------------------------------------------------------- */
/*                                    SETUP ENV                               */
/* -------------------------------------------------------------------------- */
char **init_env(char **envp);


#endif