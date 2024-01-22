/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:38:07 by emauduit          #+#    #+#             */
/*   Updated: 2023/11/07 11:38:08 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			ptr = (char *)&haystack[i];
			while (needle[j] && (needle[j] == haystack[i]) && i < len)
			{
				i++;
				j++;
			}
			if (needle[j] == '\0')
				return (ptr);
			i -= j;
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
//     char *str = "Salut a tous lol";
//     char *find = "us";
//     int n = 15;

//     printf("result real function: \n");
//     printf("%s \n", strnstr(str, find, n));
//     printf("--------------------------\n");
//     printf("result mine function: \n");
//     printf("%s \n", ft_strnstr(str, find, n));

// }