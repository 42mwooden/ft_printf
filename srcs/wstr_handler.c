/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 23:31:22 by mwooden           #+#    #+#             */
/*   Updated: 2017/05/27 23:31:24 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_build.h"

static size_t	wstrlen(wchar_t *s)
{
	size_t i;

	i = 0;
	while (*s)
	{
		if (*s <= 0x7F)
			i++;
		else if (*s <= 0x7FF)
			i += 2;
		else if (*s <= 0xFFFF)
			i += 3;
		else if (*s <= 0x10FFFF)
			i += 4;
		s++;
	}
	return (i);
}

static size_t	wstrlen_preci(wchar_t *s, int preci, size_t len)
{
	if (*s == '\0' || preci == 0)
		return (len);
	else if (*s <= 0x7F)
		return (wstrlen_preci(s + 1, preci - 1, len + 1));
	else if (*s <= 0x7FF && preci >= 2)
		return (wstrlen_preci(s + 1, preci - 2, len + 2));
	else if (*s <= 0xFFFF && preci >= 3)
		return (wstrlen_preci(s + 1, preci - 3, len + 3));
	else if (*s <= 0x10FFFF && preci >= 4)
		return (wstrlen_preci(s + 1, preci - 4, len + 4));
	else
		return (len);
}

ssize_t			wstr_handler(char **fmt, va_list *args, t_flag *flag)
{
	wchar_t	*s;
	size_t	s_len;

	(void)fmt;
	(void)flag;
	s = va_arg(*args, wchar_t*);
	if (!s)
		s = L"(null)";
	s_len = flag->has_preci ? wstrlen_preci(s, flag->preci, 0) : wstrlen(s);
	if (flag->has_width && !flag->pad_right)
		pad_width(flag->width, flag->pad_zero ? '0' : ' ', s_len);
	my_putnwstr(s, s_len);
	if (flag->has_width && flag->pad_right)
		pad_width(flag->width, ' ', s_len);
	return (flag->has_width ? my_greater(flag->width, s_len) : s_len);
}
