/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:38:03 by emauduit          #+#    #+#             */
/*   Updated: 2023/11/07 11:38:04 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < (n - 1) && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>

// int main()
// {
//     char *str = "test\200";
//     char *str1 = "test\0";
//     int n = 6;
//     printf("result real function: %d\n", strncmp(str, str1, n));
//     printf("-------------------------------------\n");
//     printf("result mine function: %d\n", ft_strncmp(str, str1, n));
// }