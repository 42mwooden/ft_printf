/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 21:27:14 by mwooden           #+#    #+#             */
/*   Updated: 2017/05/30 21:27:23 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_build.h"

ssize_t	null_handler(char **fmt, va_list *args, t_flag *flag)
{
	(void)args;
	if (flag->has_width && !flag->pad_right)
		pad_width(flag->width, flag->pad_zero ? '0' : ' ', 1);
	ft_putchar(**fmt);
	if (flag->has_width && flag->pad_right)
		pad_width(flag->width, ' ', 1);
	return (flag->has_width ? my_greater(flag->width, 1) : 1);
}

ssize_t	str_handler(char **fmt, va_list *args, t_flag *flag)
{
	char	*str;
	size_t	str_len;

	if (flag->len == l)
		return (wstr_handler(fmt, args, flag));
	else
	{
		str = va_arg(*args, char*);
		if (!str)
			str = "(null)";
		str_len = flag->has_preci ? my_lesser(flag->preci, ft_strlen(str)) :
			ft_strlen(str);
		if (flag->has_width && !flag->pad_right)
			pad_width(flag->width, flag->pad_zero ? '0' : ' ', str_len);
		my_putnstr(str, str_len);
		if (flag->has_width && flag->pad_right)
			pad_width(flag->width, ' ', str_len);
		return (flag->has_width ? my_greater(flag->width, str_len) : str_len);
	}
}
