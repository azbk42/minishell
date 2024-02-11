/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:20:25 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/11 12:39:04 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"



bool ft_init_lst_env(const char **envp)
{
    int len;
    t_env **env;
    
    env = ft_singletone_env();
    len = ft_len_env(envp);
    // if (len == 0)
    // {
    //     if (init_baby_env() == false)
    //         return (ERROR);
    // }
    len --;
    while (len >= 0)
    {   
        ft_lst_env(envp[len], env);
        if ((*env)->str == NULL || (*env)->key == NULL)
            return(ERROR);
        len--;
    }
    ft_print_env(env);
    return (OK);
}


