/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 19:00:19 by mwooden           #+#    #+#             */
/*   Updated: 2017/05/30 19:00:21 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recurse(uintmax_t num, char *base, size_t base_len, int fd)
{
	if (num >= base_len)
	{
		recurse(num / base_len, base, base_len, fd);
		recurse(num % base_len, base, base_len, fd);
	}
	else
		ft_putchar_fd(base[num], fd);
}

void		my_putnbr_base_fd(uintmax_t num, char *base, int fd)
{
	recurse(num, base, ft_strlen(base), fd);
}
