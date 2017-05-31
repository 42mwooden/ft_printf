 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 21:15:26 by mwooden           #+#    #+#             */
/*   Updated: 2017/05/27 21:15:30 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_build.h"

static void	init_handlers(t_handler *handlers)
{
	handlers['%'] = &percent_handler;
	handlers['C'] = &char_handler;
	handlers['D'] = &long_handler;
	handlers['O'] = &long_handler;
	handlers['S'] = &wstr_handler;
	handlers['U'] = &long_handler;
	handlers['X'] = &hex_handler;
	handlers['b'] = &binary_handler;
	handlers['c'] = &char_handler;
	handlers['d'] = &int_handler;
	handlers['f'] = &float_handler;
	handlers['i'] = &int_handler;
	handlers['n'] = &chars_written_handler;
	handlers['o'] = &octal_handler;
	handlers['p'] = &ptr_handler;
	handlers['s'] = &str_handler;
	handlers['u'] = &unsigned_handler;
	handlers['x'] = &hex_handler;
}

t_handler	choose_flag_handler(char flag_id)
{
	static t_handler	*handlers = NULL;

	if (!handlers)
	{
		handlers = ft_memalloc(sizeof(*handlers) * 256);
		if (handlers)
			init_handlers(handlers);
	}
	return (handlers[(int)flag_id]);
}
