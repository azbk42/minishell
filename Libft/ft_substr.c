/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:10:50 by azbreak           #+#    #+#             */
/*   Updated: 2023/11/08 15:32:17 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	length;

	i = 0;
	length = ft_strlen(s);
	if (len == 0 || (start >= length))
		return (ft_calloc(1, 1));
	if (length < (start + len))
		length = length - start;
	else
		length = len;
	str = malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	while (s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

// int main()
// {
//     char *str = "salut";
//     char *s;

//     s = ft_substr(str, 3, 1);

//     printf("%s| \n", s);

//     free(s);
// }
