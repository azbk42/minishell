/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:35:57 by azbreak           #+#    #+#             */
/*   Updated: 2024/01/08 15:20:15 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*current;
	t_list	*prev;

	current = *lst;
	if (current)
	{
		while (current)
		{
			prev = current;
			del(current->content);
			current = current->next;
			free(prev);
		}
		*lst = NULL;
	}
}
