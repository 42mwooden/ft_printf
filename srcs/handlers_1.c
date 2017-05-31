/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 21:34:33 by mwooden           #+#    #+#             */
/*   Updated: 2017/05/27 21:34:36 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_build.h"

ssize_t	percent_handler(char **fmt, va_list *args, t_flag *flag)
{
	(void)fmt;
	(void)args;
	if (flag->has_width && !flag->pad_right)
		pad_width(flag->width, flag->pad_zero ? '0' : ' ', 1);
	ft_putchar('%');
	if (flag->has_width && flag->pad_right)
		pad_width(flag->width, ' ', 1);
	return (flag->has_width ? my_greater(1, flag->width) : 1);
}

ssize_t	wchar_handler(char **fmt, va_list *args, t_flag *flag)
{
	wchar_t		c;
	unsigned	c_len;

	(void)fmt;
	c = (wchar_t)va_arg(*args, wint_t);
	if (c <= 0x7F)
		c_len = 1;
	else if (c <= 0x7FF)
		c_len = 2;
	else if (c <= 0x7FFFF)
		c_len = 3;
	else if (c <= 0x10FFFF)
		c_len = 4;
	else
		c_len = 0;
	if (flag->has_width && !flag->pad_right)
		pad_width(flag->width, flag->pad_zero ? '0' : ' ', c_len);
	my_putwchar(c);
	if (flag->has_width && flag->pad_right)
		pad_width(flag->width, flag->pad_zero ? '0' : ' ', c_len);
	return (flag->has_width ? my_greater(c_len, flag->width) : c_len);
}

ssize_t long_handler(char **fmt, va_list *args, t_flag *flag)
{
	flag->len = l;
	return (choose_flag_handler(ft_tolower(**fmt))(fmt, args, flag));
}

ssize_t	char_handler(char **fmt, va_list *args, t_flag *flag)
{
	(void)fmt;
	if (flag->has_width && !flag->pad_right)
		pad_width(flag->width, flag->pad_zero ? '0' : ' ', 1);
	ft_putchar(va_arg(*args, int));
	if (flag->has_width && flag->pad_right)
		pad_width(flag->width, ' ', 1);
	return (flag->has_width ? my_greater(1, flag->width) : 1);
}

ssize_t	float_handler(char **fmt, va_list *args, t_flag *flag)
{
	float	num;

	(void)fmt;
	(void)flag;
	num = (float)va_arg(*args, double);
	(void)num;
	ft_putstr("(float)");
	return(0);
}
