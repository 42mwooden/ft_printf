/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 23:46:58 by mwooden           #+#    #+#             */
/*   Updated: 2017/05/27 23:47:00 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	my_putnwstr(const wchar_t *s, size_t len)
{
	size_t	i;

	i = 0;
	while (*s && i < len)
	{
		if (*s <= 0x7F)
			i++;
		else if (*s <= 0x7FF)
			i += 2;
		else if (*s <= 0xFFFF)
			i += 3;
		else if (*s <= 0x10FFFF)
			i += 4;
		if (i <= len)
			my_putwchar(*s++);
	}
}
