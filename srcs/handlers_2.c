/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 15:57:13 by mwooden           #+#    #+#             */
/*   Updated: 2017/05/28 15:57:15 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_build.h"

ssize_t	hex_handler(char **fmt, va_list *args, t_flag *flag)
{
	uintmax_t	num;

	num = convert_unsigned(args, flag);
	if (**fmt == 'X')
		return (uint_handler(num, flag, "0123456789ABCDEF", "0X"));
	else
		return (uint_handler(num, flag, "0123456789abcdef", "0x"));
}

ssize_t	binary_handler(char **fmt, va_list *args, t_flag *flag)
{
	uintmax_t	num;

	(void)fmt;
	num = convert_unsigned(args, flag);
	return (uint_handler(num, flag, "01", "0b"));
}

ssize_t	chars_written_handler(char **fmt, va_list *args, t_flag *flag)
{
	(void)fmt;
	(void)args;
	(void)flag;
	return (0);
}

ssize_t	octal_handler(char **fmt, va_list *args, t_flag *flag)
{
	uintmax_t	num;

	(void)fmt;
	num = convert_unsigned(args, flag);
	if (flag->force_sharp && num == 0 && flag->has_preci && flag->preci == 0)
	{
		if (flag->has_width && !flag->pad_right)
			pad_width(flag->width, flag->pad_zero ? '0' : ' ', 1);
		ft_putstr("0");
		if (flag->has_width && flag->pad_right)
			pad_width(flag->width, ' ', 1);
		return (flag->has_width ? my_greater(flag->width, 1) : 1);
	}
	else if (flag->force_sharp && num != 0)
	{
		flag->has_preci = 1;
		flag->preci = my_greater(flag->preci, numlen(num, "01234567") + 1);
	}
	return (uint_handler(num, flag, "01234567", NULL));
}

ssize_t	ptr_handler(char **fmt, va_list *args, t_flag *flag)
{
	char		*base;
	uintmax_t	num;

	(void)fmt;
	flag->len = z;
	if (flag->has_preci)
		flag->pad_zero = 0;
	base = "0123456789abcdef";
	num = convert_unsigned(args, flag);
	return (prefix_forcer(num, base, flag, "0x"));
}
