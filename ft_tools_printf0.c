/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_printf0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:39:47 by rgatnaou          #+#    #+#             */
/*   Updated: 2021/12/09 14:39:52 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_nb(int n)
{
	int	i;

	i = 0;
	if (n < 0 || n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	len_unb(unsigned int n, int base)
{
	int	i;

	i = 0;
	if (n < 0 || n == 0)
		i++;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

int	len_ptr(unsigned	long n)
{
	int	i;

	i = 0;
	if (n < 0 || n == 0)
		i++;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_putstr(char *s)
{
	static int	i;

	i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (*s)
	{
		write(1, s, 1);
		i++;
		s++;
	}
	return (i);
}

int	ft_putnb(int n)
{
	unsigned int	ln;

	if (n < 0)
	{
		ln = n * (-1);
		ft_putchar('-');
	}
	else
		ln = n;
	if (ln > 9)
		ft_putnb(ln / 10);
	ft_putchar((ln % 10) + '0');
	return (len_nb(n));
}
