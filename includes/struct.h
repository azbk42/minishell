/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:13:12 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/26 16:30:32 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef STRUCT_H
#  define STRUCT_H

struct s_token
{
    char            *word;
    //enum            type;
    struct t_token    *next;
};

struct s_cmd_line
{
    char                *cmd;
    struct  t_token       *word;
    char                **args;
    struct  t_cmd_line    *next;
};

#endif