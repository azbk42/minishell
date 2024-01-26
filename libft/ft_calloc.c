/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:00:30 by azbreak           #+#    #+#             */
/*   Updated: 2023/11/08 17:30:03 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (size > 0 && count > SIZE_MAX / size)
		return (NULL);
	tab = malloc(count * size * sizeof(char));
	if (!tab)
		return (NULL);
	while (i < (size * count))
		tab[i++] = '\0';
	return (tab);
}
