/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azbk <azbk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:24:13 by azbreak           #+#    #+#             */
/*   Updated: 2024/02/09 16:02:08 by azbk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strncpy(new_str, s1, ft_strlen(s1));
	ft_strcat(new_str, s2);
	return (new_str);
}

// #include <stdio.h>

// int main(int ac, char *av[])
// {
//     if (ac == 3)
//         printf("%s|\n", ft_strjoin(av[1], av[2]));
// }