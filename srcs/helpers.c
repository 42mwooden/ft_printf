/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 21:48:55 by mwooden           #+#    #+#             */
/*   Updated: 2017/05/27 21:48:56 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_build.h"

uint32_t	numlen(uintmax_t num, char *base)
{
	size_t		base_int;
	uint32_t	i;

	base_int = ft_strlen(base);
	i = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= base_int;
		i++;
	}
	return (i);
}

uint32_t	find_strlen_num(uintmax_t num, char *base, char *ptr, t_flag *flag)
{
	uint32_t	num_len;
	uint32_t	str_len;

	num_len = numlen(num, base);
	if (num == 0 && flag->has_preci && flag->preci == 0)
		str_len = 0;
	else
		str_len = num_len;
	if (flag->force_sign && ptr != NULL && num != 0)
		str_len += ft_strlen(ptr);
	return (str_len);
}

uintmax_t	convert_unsigned(va_list *args, t_flag *flag)
{
	uintmax_t	num;

	num = va_arg(*args, uintmax_t);
	if (flag->len == hh)
		num = (unsigned char)num;
	else if (flag->len == h)
		num = (unsigned short int)num;
	else if (flag->len == l)
		num = (unsigned long int)num;
	else if (flag->len == ll)
		num = (unsigned long long int)num;
	else if (flag->len == j)
		num = (uintmax_t)num;
	else if (flag->len == z)
		num = (size_t)num;
	else
		num = (unsigned int)num;
	return (num);
}

void		pad_width(int width, char pad_with, int num)
{
	while (num < width)
	{
		ft_putchar(pad_with);
		num++;
	}
}

ssize_t		sign_forcer(uintmax_t num, char *base, t_flag *flag, char *sign)
{
	unsigned	num_len;
	size_t		num_trim;

	num_len = find_strlen_num(num, base, NULL, flag) + ft_strlen(sign);
	num_trim = ft_strlen(sign);
	if (flag->has_width && !flag->pad_right && !flag->pad_zero)
	{
		pad_width(flag->width, ' ', num_len);
		num_trim += my_greater(flag->width - num_len, 0);
		flag->has_width = 0;
	}
	else if (flag->has_width)
		flag->width -= ft_strlen(sign);
	ft_putstr(sign);
	return (uint_handler(num, flag, base, NULL) + num_trim);
}
