/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:37:41 by emauduit          #+#    #+#             */
/*   Updated: 2023/11/07 11:37:42 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
//     char *str = "Salutl";
//     char *test;

//     printf("result real fonction: \n");
//     test = strchr(str, 'K');
//     printf("%s \n", test);

//     printf("----------------------\n");

//     char *str1 = "Salutl";
//     char *test1;

//     printf("result mine fonction: \n");
//     test1 = ft_strchr(str1, 'K');
//     printf("%s \n", test1);
// }