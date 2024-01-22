/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:02:31 by azbreak           #+#    #+#             */
/*   Updated: 2023/11/07 11:37:59 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	n;

	n = 0;
	i = 0;
	len = 0;
	while (src[len])
	{
		len++;
	}
	while (dest[n])
	{
		n++;
	}
	if (size == 0)
		return (len);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	srclen;
// 	size_t	dstlen;
// 	size_t	i;

// 	i = 0;
// 	dstlen = 0;
// 	srclen = 0;
// 	while (src[srclen])
// 		srclen++;
// 	while (dst[dstlen])
// 		dstlen++;
// 	if (size == 0)
// 		return (srclen);
// 	while (src[i] && i < (size - 1))
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (srclen);
// }
