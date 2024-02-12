/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:10:10 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/12 14:15:16 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void ft_print_env(t_env **env)
{
    t_env *cur;

    cur = *env;
    while (cur)
    {   
        printf("%s\n", cur->str);
        // printf("key = %s\n", cur->key);
        // printf("value = %s\n", cur->value);
        cur = cur->next;
    }
}
