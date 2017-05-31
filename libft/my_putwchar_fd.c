/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 22:32:06 by mwooden           #+#    #+#             */
/*   Updated: 2017/05/27 22:32:09 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	my_putwchar_fd(wchar_t c, int fd)
{
	if (c <= 0x7F)
		ft_putchar_fd(c, fd);
	else if (c <= 0x7FF)
	{
		ft_putchar_fd((c >> 6) + 0xC0, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar_fd((c >> 12) + 0xE0, fd);
		ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar_fd((c >> 18) + 0xF0, fd);
		ft_putchar_fd(((c >> 12) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
}
