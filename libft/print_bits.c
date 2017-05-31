/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 09:23:05 by exam              #+#    #+#             */
/*   Updated: 2017/05/22 00:30:10 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_bits(unsigned char to_print)
{
	int		byte;
	char	out[8];
	int		i;

	i = -1;
	while (++i < 8)
		out[i] = '0';
	i = 7;
	byte = to_print;
	while (byte > 0)
	{
		if (byte % 2 == 1)
			out[i] = '1';
		i--;
		byte /= 2;
	}
	i = 0;
	while (i < 8)
	{
		write(1, &out[i], 1);
		i++;
	}
}
