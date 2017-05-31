/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 22:22:27 by mwooden           #+#    #+#             */
/*   Updated: 2017/05/28 22:22:29 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_build.h"

static void	conv_put(uintmax_t num, char *base, t_flag *flag, unsigned num_len)
{
	if (flag->has_preci)
		pad_width(flag->preci, base[0], num_len);
	if (num == 0 && flag->has_preci && flag->preci == 0)
		return ;
	else
		my_putnbr_base(num, base);
}

ssize_t		uint_handler(uintmax_t num, t_flag *flag, char *base, char *sign)
{
	uint32_t	num_len;
	uint32_t	str_len;

	if (flag->has_preci)
		flag->pad_zero = 0;
	num_len = numlen(num, base);
	if (flag->has_width && !flag->pad_zero)
	{
		if (flag->has_preci)
			flag->preci = my_greater(flag->width, flag->preci);
		else
			flag->preci = my_greater(flag->width, num_len);
		flag->has_preci = 1;
		flag->has_width = 0;
	}
	str_len = find_strlen_num(num, base, sign, flag);
	if (flag->has_width && !flag->pad_right)
		pad_width(flag->width, ' ', str_len);
	conv_put(num, base, flag, num_len);
	if (flag->has_width && flag->pad_right)
		pad_width(flag->width, ' ', str_len);
	return (flag->has_width ? my_greater(str_len, flag->width) : str_len);
}

ssize_t	unsigned_handler(char **fmt, va_list *args, t_flag *flag)
{
	uintmax_t	num;

	(void)fmt;
	num = convert_unsigned(args, flag);
	return (uint_handler(num, flag, "0123456789", NULL));
}
