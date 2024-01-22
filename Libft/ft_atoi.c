/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:00:12 by azbreak           #+#    #+#             */
/*   Updated: 2023/11/07 11:36:24 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	result;

	result = 0;
	minus = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			minus *= -1;
	while (str[i] > 47 && str[i] < 58)
		result = (result * 10) + (str[i++] - '0');
	return (result * minus);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "  \t\r\v    -+42abc85d";
// 	printf("real atoi = %d\n", atoi(str));
// 	printf("result = %d\n", ft_atoi(str));
// }
