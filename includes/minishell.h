/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:04:56 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/12 11:58:16 by emauduit         ###   ########.fr       */
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
/*                                    FREE                                    */
/* -------------------------------------------------------------------------- */
void ft_free_env_list(t_env **env);
void free_strs(char *s1, char *s2);

#endif