/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:38:12 by emauduit          #+#    #+#             */
/*   Updated: 2023/11/07 11:49:37 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
//     char *str = "Salutl";
//     char *test;

//     printf("result real fonction: \n");
//     test = strrchr(str, 'l');
//     printf("%s \n", test);

//     printf("----------------------\n");

//     char *str1 = "Salutl";
//     char *test1;

//     printf("result mine fonction: \n");
//     test1 = ft_strrchr(str1, 'l');
//     printf("%s \n", test1);
// }