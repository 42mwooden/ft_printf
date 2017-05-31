/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_build.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 18:21:17 by mwooden           #+#    #+#             */
/*   Updated: 2017/05/27 18:21:19 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BUILD_H
# define FT_PRINTF_BUILD_H

# include <stdarg.h>
# include "libft.h"

typedef struct	s_flag
{
	int			force_sharp : 1;
	int			pad_zero : 1;
	int			pad_right : 1;
	int			force_sign : 1;
	int			blank_sign : 1;
	int			has_width : 1;
	int			has_preci : 1;
	uint32_t	width;
	uint32_t	preci;
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

uint32_t	numlen(uintmax_t num, char *base);

uint32_t	find_strlen_num(uintmax_t num, char *base, char *ptr, t_flag *flag);

ssize_t		prefix_forcer(uintmax_t num, char *base, t_flag *flag, char *sign);

/*
** Handlers
*/
ssize_t		percent_handler(char **fmt, va_list *args, t_flag *flag);

ssize_t		wchar_handler(char **fmt, va_list *args, t_flag *flag);

ssize_t 	long_handler(char **fmt, va_list *args, t_flag *flag);

ssize_t		wstr_handler(char **fmt, va_list *args, t_flag *flag);

ssize_t		hex_handler(char **fmt, va_list *args, t_flag *flag);

ssize_t		binary_handler(char **fmt, va_list *args, t_flag *flag);

ssize_t		char_handler(char **fmt, va_list *args, t_flag *flag);

ssize_t		float_handler(char **fmt, va_list *args, t_flag *flag);

ssize_t		int_handler(char **fmt, va_list *args, t_flag *flag);

ssize_t		chars_written_handler(char **fmt, va_list *args, t_flag *flag);

ssize_t		octal_handler(char **fmt, va_list *args, t_flag *flag);

ssize_t		unsigned_handler(char **fmt, va_list *args, t_flag *flag);

ssize_t		null_handler(char **fmt, va_list *args, t_flag *flag);

ssize_t		ptr_handler(char **fmt, va_list *args, t_flag *flag);

ssize_t		str_handler(char **fmt, va_list *args, t_flag *flag);

ssize_t		uint_handler(uintmax_t num, t_flag *flag, char *base, char *sign);

typedef 	ssize_t	(*t_handler)(char **, va_list *, t_flag*);
t_handler	choose_flag_handler(char flag_id);

#endif
