/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:02:28 by azbreak           #+#    #+#             */
/*   Updated: 2023/11/07 11:37:57 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	lendest;

	i = 0;
	len = ft_strlen(dest) + ft_strlen(src);
	lendest = ft_strlen(dest);
	if (lendest >= size)
		return (size + ft_strlen(src));
	if (size == 0)
		return (len);
	while (src[i] && (i < (size - lendest - 1)))
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = '\0';
	return (len);
}
