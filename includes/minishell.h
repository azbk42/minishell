/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:04:56 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/12 15:23:43 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
#include "struct.h"
#include "builtin.h"
#include "parsing.h"
#include <stdio.h>

# define MALLOC_ERROR NULL
# define VAR_EMPTY NULL

# define ERROR false
# define OK true



void print_error(const char *message);





/* -------------------------------------------------------------------------- */
/*                                    SINGLETON                               */
/* -------------------------------------------------------------------------- */
t_env	**ft_singletone_env(void);


/* -------------------------------------------------------------------------- */
/*                                    FREE                                    */
/* -------------------------------------------------------------------------- */
void ft_free_env_list(t_env **env);
void free_strs(char *s1, char *s2);

void	ft_free_data(t_data *data);
void	ft_free_commands(t_cmd_line *command);
void	ft_free_cmd(t_cmd_line *cmd);
void	ft_free_array(char **tab);
void	ft_free_tokens(t_token *tokens);


#endif