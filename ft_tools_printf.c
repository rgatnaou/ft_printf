/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:46:15 by rgatnaou          #+#    #+#             */
/*   Updated: 2021/12/09 14:59:04 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunb(unsigned int n)
{
	if (n > 9)
		ft_putunb(n / 10);
	ft_putchar((n % 10) + '0');
	return (len_unb(n, 10));
}

int	ft_hex(unsigned int h)
{
	char	*t_h;

	t_h = "0123456789abcdef";
	if (h > 15)
		ft_hex(h / 16);
	ft_putchar(t_h[h % 16]);
	return (len_unb(h, 16));
}

int	ft_hexa(unsigned int h)
{
	char	*t_h;

	t_h = "0123456789ABCDEF";
	if (h > 15)
		ft_hexa(h / 16);
	ft_putchar(t_h[h % 16]);
	return (len_unb(h, 16));
}

int	ft_hex_ptr(unsigned long h)
{
	char	*t_h;

	t_h = "0123456789abcdef";
	if (h > 15)
		ft_hex_ptr(h / 16);
	ft_putchar(t_h[h % 16]);
	return (len_ptr(h));
}

int	ft_putptr(unsigned long p)
{
	return (ft_putstr("0x") + ft_hex_ptr(p));
}
