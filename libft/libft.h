/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 16:33:56 by mwooden           #+#    #+#             */
/*   Updated: 2017/01/07 23:55:29 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define UPPER(x) (x >= 65 && x <= 90)
# define LOWER(x) (x >= 97 && x <= 122)
# define ALPHA(x) (UPPER(x) || LOWER(x))
# define DIGIT(x) (x >= 48 && x <= 57)
# define ALNUM(x) (ALPHA(x) || DIGIT(x))
# define BUFF_SIZE 500

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <fcntl.h>
# include <ctype.h>
# include <wchar.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_line
{
	int				fd;
	int				red;
	char			*line;
	struct s_line	*next;
}					t_line;

void				ft_putchar(char c);

void				ft_putnbr(int nb);

void				ft_putstr(const char *s);

size_t				ft_strlen(const char *s);

char				*ft_strcat(char *s1, const char *s2);

char				*ft_strncat(char *s1, const char *s2, size_t n);

size_t				ft_strlcat(char *dst, const char *src, size_t size);

int					ft_atoi(char *str);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strcpy(char *dst, const char *src);

char				*ft_strncpy(char *dst, const char *src, size_t len);

char				*ft_strstr(const char *big, const char *little);

char				*ft_strnstr(const char *big, const char *little,
					size_t len);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isascii(int c);

int					ft_isalnum(int c);

int					ft_isprint(int c);

int					ft_tolower(int c);

int					ft_toupper(int c);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

void				ft_putendl(const char *s);

char				*ft_itoa(int n);

void				ft_putnbr_fd(int n, int fd);

void				ft_putstr_fd(const char *s, int fd);

void				ft_putendl_fd(const char *s, int fd);

void				ft_putchar_fd(char c, int fd);

char				**ft_strsplit(const char *s, char c);

char				*ft_strtrim(const char *s);

char				*ft_strjoin(const char *s1, const char *s2);

char				*ft_strsub(const char *s, unsigned int start, size_t len);

int					ft_strequ(const char *s1, const char *s2);

int					ft_strnequ(const char *s1, const char *s2, size_t n);

char				*ft_strmap(const char *s, char (*f)(char));

char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char*));

void				ft_strclr(char *s);

void				ft_strdel(char **as);

char				*ft_strnew(size_t size);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

void				*ft_memset(void *b, int c, size_t len);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

char				*ft_strdup(const char *s1);

/*
**Bonus Section
*/

t_list				*ft_lstnew(const void *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**Personal Additions
*/

int					ft_isprime(int nb);

int					ft_primefact(int num, int **tab);

t_list				**ft_lstrev(t_list **begin);

int					ft_power(int nb, int power);

int					ft_sqrt(int nb);

int					ft_escape(void *a, void *b, void *c, void *d);

void				*my_realloc(void *ptr, size_t size, size_t diff);

int					get_next_line(const int fd, char **line);

void				print_bits(unsigned char to_print);

int					my_greater(int nbr1, int nbr2);

int					my_lesser(int nbr1, int nbr2);

void				my_putwchar_fd(wchar_t, int fd);

void				my_putwchar(wchar_t);

void				my_putwstr_fd(wchar_t *s, int fd);

void				my_putwstr(wchar_t *s);

void				my_putnwstr(const wchar_t *s, size_t len);

void				my_putnbr_base_fd(uintmax_t num, char *base, int fd);

void				my_putnbr_base(uintmax_t num, char *base);

void				my_putnstr_fd(const char *str, size_t str_len, int fd);

void				my_putnstr(const char *str, size_t str_len);

#endif
