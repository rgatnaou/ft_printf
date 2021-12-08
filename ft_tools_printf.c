/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:46:15 by rgatnaou          #+#    #+#             */
/*   Updated: 2021/12/08 19:38:43 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int len_nb(int n)
{
	int i;
	i = 0;
	if (n <0 || n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
int len_unb(unsigned int n,int base)
{
	int i;
	i = 0;
	if (n <0 || n == 0)
		i++;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}
int len_ptr(unsigned	long n)
{
	int i;
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
int ft_putchar(char c)
{
	write(1,&c,1);
	return(1);
}

int	ft_putstr(char *s)
{
	static int i;

	i = 0;
	if (s == NULL)
		return(write(1,"(null)",6));
	while (*s)
	{
		write(1,s,1);
		i++;
		s++;
	}
	return(i);
}

int ft_putnb(int n)
{
	unsigned int ln;

	if (n < 0 )
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
int ft_putunb(unsigned int n)
{
    if (n > 9)
        ft_putunb(n / 10);
    ft_putchar((n % 10) + '0');
	return (len_unb(n,10));
}
int	ft_hex(unsigned int h)
{
	char *t_h;

	t_h = "0123456789abcdef";
    if (h > 15)
        ft_hex(h / 16);
    ft_putchar(t_h[h % 16]);
	return (len_unb(h,16));
}
int	FT_HEX(unsigned int h)
{
	char *t_h;

	t_h = "0123456789ABCDEF";
    if (h > 15)
        FT_HEX(h / 16);
    ft_putchar(t_h[h % 16]);
	return (len_unb(h,16));
}

int	ft_hex_ptr(unsigned long h)
{
	char *t_h;

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
