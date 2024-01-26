/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:39:12 by azbk              #+#    #+#             */
/*   Updated: 2023/12/29 15:23:33 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_count(const char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr_count(const char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*count) += 6;
		return ;
	}
	while (str[i])
		ft_putchar_count(str[i++], count);
}

void	print_hexa_count(int *count, unsigned long nbr, char letter,
		unsigned int base)
{
	char	*hexa_min;
	char	*hexa_maj;
	char	*decimal;

	hexa_min = "0123456789abcdef";
	hexa_maj = "0123456789ABCDEF";
	decimal = "0123456789";
	if (nbr >= base)
	{
		print_hexa_count(count, nbr / base, letter, base);
		print_hexa_count(count, nbr % base, letter, base);
	}
	else if (letter == 'x')
		ft_putchar_count(hexa_min[nbr], count);
	else if (letter == 'X')
		ft_putchar_count(hexa_maj[nbr], count);
	else
		ft_putchar_count(decimal[nbr], count);
}

void	ft_putnbr_count(int nb, int *count)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar_count('-', count);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_count(nbr / 10, count);
		ft_putnbr_count(nbr % 10, count);
	}
	else
		ft_putchar_count(nbr + '0', count);
}

void	print_adress_count(void *add, int *count)
{
	unsigned long int	nbr;

	nbr = 0;
	if (add == NULL)
		ft_putstr_count("(nil)", count);
	else
	{
		nbr = (unsigned long int)add;
		ft_putstr_count("0x", count);
		print_hexa_count(count, nbr, 'x', 16);
	}
}
