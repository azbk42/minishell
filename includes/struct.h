/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:13:12 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/12 14:49:56 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_token		t_token;
typedef struct s_cmd_line	t_cmd_line;
typedef struct s_env		t_env;

typedef enum token
{
	NON,
	ARG,           // word
	BUILTIN,       // builtin
	OPEN_FILE,     //  word following '<'
	HERE_DOC,      // word == '<<'
	LIMITOR,       // word following '<<'
	CREAT_FILE,    // word following '>'
	WRITE_FILE,    // word following '>>'
	FILE_IN,       // word == '<'
	FILE_OUT,      // word == '>'
	FILE_OUT_OVER, // word == '>>'
}							t_e_token;

typedef struct s_token
{
	char					*token;
	t_e_token				type;
	t_token					*next;
}							t_token;

typedef struct s_cmd_line
{
	char					*cmd;
	t_token					*token_list;
	char					**args;
	t_cmd_line				*next;
}							t_cmd_line;

typedef struct s_data
{
	t_token					*t;
	t_cmd_line				*cmd_list;
}							t_data;

typedef struct s_env
{
	char 					*str;
	char					*key;
	char					*value;
	t_env					*next;
}							t_env;

#endif