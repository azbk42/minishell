/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:37:21 by emauduit          #+#    #+#             */
/*   Updated: 2023/11/07 11:47:32 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*p;
	const unsigned char	*src1;
	size_t				i;

	if (dest == NULL || src == NULL || n == 0)
		return (dest);
	i = 0;
	src1 = src;
	p = dest;
	while (i < n)
	{
		p[i] = src1[i];
		i++;
	}
	return (dest);
}

// int main()
// {
//     printf("test real memcpy: \t\t\n");
//     char dest[8];
//     char *src = NULL;
//     memcpy(dest, src, 6);
//     printf("%s \n", dest);
//     printf("------------------------\n");

//     printf("test mine ft_memcpy: \t\t\n");
//     char dest2[8];
//     char *src1 = NULL;
//     ft_memcpy(dest2, src1, 6);
//     printf("%s \n", dest2);
// }