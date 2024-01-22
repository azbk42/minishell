/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:37:19 by emauduit          #+#    #+#             */
/*   Updated: 2023/11/07 12:04:56 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str;
	const unsigned char	*str1;
	size_t				i;

	if (n == 0)
		return (0);
	str = s1;
	str1 = s2;
	i = 0;
	while (i < n)
	{
		if (str[i] != str1[i])
			return ((int)(str[i] - str1[i]));
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main()
// {
//     char str[] = {0, 0, 127, 0};
//     char s[] = {-50, 0, 127, 0};
// 	char str1[] = {0, 0, 42, 0};
//     int n = 1;

//     printf("Test real function: \n");
//     printf("result = %d \n", memcmp(s, str, n));
//     printf("------------------------\n");
//     printf("Test mine function: \n");
//     printf("result = %d \n", ft_memcmp(s, str, n));
// }