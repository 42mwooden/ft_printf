/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 17:51:01 by mwooden           #+#    #+#             */
/*   Updated: 2017/05/28 17:51:03 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_build.h"

intmax_t	convert_signed(va_list *args, t_flag *flag)
{
	intmax_t	num;

	num = va_arg(*args, uintmax_t);
	if (flag->len == hh)
		num = (char)num;
	else if (flag->len == h)
		num = (short int)num;
	else if (flag->len == l)
		num = (long int)num;
	else if (flag->len == ll)
		num = (long long int)num;
	else if (flag->len == j)
		num = (intmax_t)num;
	else if (flag->len == z)
		num = (size_t)num;
	else
		num = (int)num;
	return (num);
}

ssize_t	int_handler(char **fmt, va_list *args, t_flag *flag)
{
	intmax_t	num;
	char		*sign;

	(void)fmt;
	if (flag->has_preci)
		flag->pad_zero = 0;
	num = convert_signed(args, flag);
	if (num < 0 || flag->force_sign || flag->blank_sign)
	{
		if (num < 0)
		{
			num = -num;
			sign = "-";
		}
		else if (flag->force_sign)
			sign = "+";
		else if (flag->blank_sign)
			sign = " ";
		else
			sign = "";
		return (sign_forcer(num, "0123456789", flag, sign));
	}
	else
		return (uint_handler(num, flag, "0123456789", NULL));
}
