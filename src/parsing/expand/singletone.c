/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:38:49 by emauduit          #+#    #+#             */
/*   Updated: 2024/02/11 12:39:08 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_env	**ft_singletone_env(void)
{
	static t_env	*singletone = NULL;

	return (&singletone);
}
