/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 03:51:41 by bhamdi            #+#    #+#             */
/*   Updated: 2018/07/24 23:08:18 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"
# define SIZEBUF 1985
# define SPECIFIER "aAcCdDeEfFgGinoOpsSuUxX%"
# define FLAGS "-+ #0"
# define WIDTH "0123456789*"
# define PRECISION "."
# define LENGTH "hljztL"

typedef struct	s_format
{
	va_list		args;
	char		*fmt;
	int			i;
	int			j;
}				t_format;

typedef struct	s_data
{
	char		data[SIZEBUF + 1];
	size_t		index;
	size_t		len;
}				t_data;

typedef struct	s_option
{
	char		sharp;
	char		zero;
	char		space;
	int			left;
	int			sign;

	int			i_width;
	int			c_width;

	int			i_preci;
	int			c_preci;

	char		length[3];

	char		speci;

	va_list		*argptr;
}				t_option;

char			find(const char *s, char c);
int				main(void);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(char *str);
void			ft_putendl(char const *s);
void			ft_bzero(void *s, size_t n);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
int				ft_printf(const char *restrict format, ...);
int				find_define(t_option *flag, t_format *fmtptr);
int				processing(t_format *fmtptr, t_data *data);
int				error(int j);
void			apply_speci(t_data *data, t_option *flag);
void			flush_data(t_data *data);
int				stock(t_data *data, char *fmt, int len);
void			init_option(t_option *flag, va_list *args, int bt);
int             find_int(t_option *flag, t_format *fmtptr, int a);


void    filling(char *filling, char *exe, t_data *data, t_option *flag);
void    ft_percent(t_data *data, t_option *flag);
void    ft_char(t_data *data, t_option *flag);
void    ft_str(t_data *data, t_option *flag);
void    ft_int(t_data *data, t_option *flag);
void    ft_uint(t_data *data, t_option *flag);
void    ft_double(t_data *data, t_option *flag);
void    ft_pint(t_data *data, t_option *flag);
void    ft_void(t_data *data, t_option *flag);
int		ft_intlen(long n);
int		ft_atoi1(t_format *fmtptr);
char	*ft_itoa1(long n);


#endif
