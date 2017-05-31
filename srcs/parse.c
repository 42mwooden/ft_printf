/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 20:01:26 by mwooden           #+#    #+#             */
/*   Updated: 2017/05/27 20:01:30 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_build.h"

char	*parse_len(char **fmt, t_flag *flag)
{
	if (**fmt == 'h' && *(*fmt + 1) == 'h')
	{
		flag->len = hh;
		return (*fmt += 2);
	}
	else if (**fmt == 'l' && *(*fmt + 1) == 'l')
	{
		flag->len = ll;
		return (*fmt += 2);
	}
	else if (**fmt == 'h' || **fmt == 'j' || **fmt == 'l' || **fmt == 'z')
	{
		if (**fmt == 'h')
			flag->len = h;
		else if (**fmt == 'j')
			flag->len = j;
		else if (**fmt == 'l')
			flag->len = l;
		else if (**fmt == 'z')
			flag->len = z;
		return ((*fmt)++);
	}
	else
		return (*fmt);
}

char	*parse_preci(char **fmt, t_flag *flag, va_list *args)
{
	int		preci;

	if (**fmt == '.')
	{
		(*fmt)++;
		if (**fmt == '*')
		{
			(*fmt)++;
			if ((preci = va_arg(*args, int)) >= 0)
			{
				flag->has_preci = 1;
				flag->preci = preci;
			}
			return (*fmt);
		}
		else
		{
			while (ft_isdigit(**fmt))
				flag->preci = flag->preci * 10 + (*(*fmt)++ - '0');
			flag->preci = 1;
			return (*fmt);
		}
	}
	else
		return (*fmt);
}

char	*parse_width(char **fmt, t_flag *flag, va_list *args)
{
	int		check;

	flag->width = 0;
	while (**fmt == '*' || ft_isdigit(**fmt))
	{
		if (**fmt == '*')
		{
			(*fmt)++;
			check = va_arg(*args, int);
			if (check < 0)
				flag->pad_right = 1;
			flag->width = check < 0 ? -check : check;
			flag->has_width = 1;
		}
		else if (ft_isdigit(**fmt))
		{
			flag->has_width = 1;
			flag->width += 0;
			while(ft_isdigit(**fmt))
				flag->width = flag->width * 10 + (*(*fmt)++ - '0');
		}
	}
	return (*fmt);
}

char	*parse_flag(char **fmt, t_flag *flag)
{
	if (**fmt == '#' || **fmt == '0' || **fmt == '-' ||
		**fmt == '+' || **fmt == ' ')
	{
		if (**fmt == '#')
			flag->pound_conv = 1;
		else if (**fmt == '0')
			flag->pad_zero = 1;
		else if (**fmt == '-')
			flag->pad_right = 1;
		else if (**fmt == '+')
			flag->force_sign = 1;
		else if (**fmt == '0')
			flag->blank_sign = 1;
		(*fmt)++;
		if (flag->pad_right)
			flag->pad_zero = 0;
		return (parse_flag(fmt, flag));
	}
	else
		return (*fmt);
}
