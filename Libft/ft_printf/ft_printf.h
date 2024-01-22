/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:44:44 by azbk              #+#    #+#             */
/*   Updated: 2024/01/20 14:35:01 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putstr_count(const char *str, int *count);
void	ft_putchar_count(const char c, int *count);
void	print_hexa_count(int *count, unsigned int long nbr, char letter, \
			unsigned int base);
void	ft_putnbr_count(int nb, int *count);
void	print_adress_count(void *add, int *count);

#endif