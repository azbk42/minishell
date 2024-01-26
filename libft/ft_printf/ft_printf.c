/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:44:38 by azbk              #+#    #+#             */
/*   Updated: 2023/12/29 15:29:55 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsing_format(int *count, char format, va_list args)
{
	if (format == '%')
		ft_putchar_count('%', count);
	else if (format == 'c')
		ft_putchar_count(va_arg(args, int), count);
	else if (format == 's')
		ft_putstr_count(va_arg(args, char *), count);
	else if (format == 'x' || format == 'X')
		print_hexa_count(count, va_arg(args, unsigned int), format, 16);
	else if (format == 'i' || format == 'd')
		ft_putnbr_count(va_arg(args, int), count);
	else if (format == 'u')
		print_hexa_count(count, va_arg(args, unsigned int), format, 10);
	else if (format == 'p')
		print_adress_count(va_arg(args, void *), count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			parsing_format(&count, format[i], args);
			i++;
		}
		else
			ft_putchar_count(format[i++], &count);
	}
	va_end(args);
	return (count);
}
