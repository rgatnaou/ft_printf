/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:18:10 by rgatnaou          #+#    #+#             */
/*   Updated: 2021/12/08 19:12:36 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include<unistd.h>

int ft_putchar(char c);
int	ft_putstr(char *s);
int ft_putnb(int ln);
int ft_putunb(unsigned int n);
int	ft_putptr(unsigned long p);
int	ft_hex(unsigned int h);
int	FT_HEX(unsigned int h);
int	ft_printf(const char *pri, ...);
int	ft_eval(va_list ap, char c);
int	ft_hex_ptr(unsigned long h);

#endif