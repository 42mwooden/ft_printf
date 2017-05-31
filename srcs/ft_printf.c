/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 16:42:04 by mwooden           #+#    #+#             */
/*   Updated: 2017/05/27 16:42:06 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_build.h"

static ssize_t	create_flag(char **fmt, va_list *args, t_flag *flag)
{
	ssize_t		ret;
	t_handler	handler;

	if ((*(++*fmt)) == '\0')
		return (0);
	if (!(parse_flag(fmt, flag)))
		return (-1);
	if (!(parse_width(fmt, flag, args)))
		return (-1);
	if (!(parse_preci(fmt, flag, args)))
		return (-1);
	if (!(parse_len(fmt, flag)))
		return (-1);
	if (**fmt == '\0')
		return (0);
	if (!choose_flag_handler(**fmt))
		handler = null_handler;
	else
		handler = choose_flag_handler(**fmt);
	ret = handler(fmt, args, flag);
	(*fmt)++;
	return (ret);
}

static int		printf_recurse(const char *fmt, va_list *args, size_t s)
{
	char	*cur;
	t_flag	arg_flag;
	ssize_t	flag_len;

	cur = ft_strchr(fmt, '%');
	if (*fmt == '\0')
		return (s);
	if (cur == NULL)
	{
		ft_putstr(fmt);
		return (s + ft_strlen(fmt));
	}
	else if (cur > fmt)
	{
		my_putnstr(fmt, cur - fmt);
		return(printf_recurse(cur, args, s + (cur - fmt)));
	}
	else
	{
		ft_bzero(&arg_flag, sizeof(t_flag));
		if ((flag_len = create_flag((char **)&fmt, args, &arg_flag)) < 0)
			return (-1);
		else
			return (printf_recurse(fmt, args, s + flag_len));
	}
}

int				ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		ret;

	va_start(args, fmt);
	ret = printf_recurse(fmt, &args, 0);
	va_end(args);
	return (ret);
}
