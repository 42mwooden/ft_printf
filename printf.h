/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 18:21:17 by mwooden           #+#    #+#             */
/*   Updated: 2017/05/27 18:21:19 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "printf.h"

typedef struct	s_flag
{
	int			pound_conv : 1;
	int			pad_zero : 1;
	int			pad_right : 1;
	int			force_sign : 1;
	int			blank_sign : 1;
	int			has_width : 1;
	int			has_preci : 1;
	uint32		width;
	uint32		preci;
	enum
	{
				no_len,
				hh,
				h,
				l,
				ll,
				j,
				z
	}			len;
}				t_flag;

/*
** Parse
*/
char		*parse_flag(char **fmt, t_flag *flag);

char		*parse_width(char **fmt, t_flag *flag, va_list *args);

char		*parse_preci(char **fmt, t_flag *flag, va_list *args);

char		*parse_len(char **fmt, t_flag *flag);

/*
** Helpers
*/
uintmax_t	convert_unsigned(va_list *args, t_flag *flag);

void		pad_width(int width, char pad_with, int num);

uint32		numlen(uintmax_t num, char *base);

uint32		find_strlen_num(uintmax_t num, char *base, char *ptr, t_flag *flag);

/*
** Handlers
*/
ssize_t		percent_handler(char **fmt, va_list args, t_flag *flag);

ssize_t		wchar_handler(char **fmt, va_list *args, t_flag *flag);

ssize_t 	long_handler(char **fmt, va_list *args, t_flag *flag);

ssize_t		wstr_handler(char **fmt, va_list *args, t_flag *flag);

typedef 	ssize_t	(*t_handler)(char **, va_list *, t_flag);

t_handler	choose_flag_handler(char flag_id);

#endif
