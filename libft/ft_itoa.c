/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:38:54 by azbreak           #+#    #+#             */
/*   Updated: 2023/11/07 11:46:32 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nbr)
{
	int		len;
	long	tmp;

	len = 0;
	tmp = (long)nbr;
	if (nbr == 0)
		return (1);
	if (tmp < 0)
	{
		len++;
		tmp *= -1;
	}
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	result;
	int		occurence;
	int		i;

	i = 0;
	occurence = ft_len(n);
	result = n;
	str = malloc(occurence * sizeof(char) + 1);
	if (!str)
		return (NULL);
	if (result < 0)
	{
		str[0] = '-';
		i++;
		result *= -1;
	}
	str[occurence] = '\0';
	while (i < occurence)
	{
		str[occurence - 1] = (result % 10) + '0';
		result /= 10;
		occurence--;
	}
	return (str);
}
// #include <stdio.h>

// int main()
// {
//     int nb = 0;

//     printf("------------------\n");
//     printf("mine function: \n");
//     printf("%s|\n", ft_itoa(nb));
// }