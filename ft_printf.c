/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:15:47 by rgatnaou          #+#    #+#             */
/*   Updated: 2021/12/09 15:16:37 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_eval(va_list ap, char c)
{
	int	x;

	x = 0;
	if (c == '%')
		x = ft_putchar('%');
	else if (c == 'd')
		x = ft_putnb(va_arg(ap, int));
	else if (c == 'i')
		x = ft_putnb(va_arg(ap, int));
	else if (c == 'c')
		x = ft_putchar(va_arg(ap, int));
	else if (c == 's')
		x = ft_putstr(va_arg(ap, char *));
	else if (c == 'X')
		x = ft_hexa(va_arg(ap, int));
	else if (c == 'x')
		x = ft_hex(va_arg(ap, int));
	else if (c == 'p')
		x = ft_putptr(va_arg(ap, unsigned long));
	else if (c == 'u')
		x = ft_putunb(va_arg(ap, int));
	else
		x = ft_putchar(c);
	return (x);
}

int	ft_printf(const char *pri, ...)
{
	int		x;
	int		i;
	va_list	ap;

	if (!pri)
		return (0);
	x = 0;
	i = 0;
	va_start(ap, pri);
	while (pri[i])
	{
		if (pri[i] == '%')
		{
			i++;
			x += ft_eval(ap, pri[i]);
		}
		else
			x += ft_putchar(pri[i]);
		i++;
	}
	va_end(ap);
	return (x);
}
