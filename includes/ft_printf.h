/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 03:51:41 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/21 07:49:58 by bhamdi           ###   ########.fr       */
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
# define SIZEBUF 1985
# define SPECIFIER "aAcCdDeEfFgGinoOpsSuUxX%"
# define FLAGS "-0123456789"
# define WIDTH "0123456789*"
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
	char		exe[SIZEBUF + 1];
	int			i;
		
	char		data[SIZEBUF + 1];
	size_t		index;
	size_t		len;
}				t_data;

typedef struct	s_option
{
	char		sharp;
	char		zero;
	char		space;
	char		plus;
	int			sign;

	int			width;

	int			preci;

	char		length;

	char		speci;

	va_list		*argptr;
}				t_option;

char			find(const char *s, char c);
int				ft_printf(const char *restrict format, ...);
int				find_define(t_option *flag, t_format *fmtptr);
int				processing(t_format *fmtptr, t_data *data);
int				error(int j);
void			apply_speci(t_data *data, t_option *flag);
void			flush_data(t_data *data);
int				stock(t_data *data, char *fmt, int len);
void			init_option(t_option *flag, va_list *args, int bt);
char			*filling_int(int exe, t_data *data, t_option *flag);
char			*filling_uint(int exe, t_data *data, t_option *flag);
void			filling(char *exe, t_data *data, t_option *flag);
void			ft_percent(t_data *data, t_option *flag);
void			ft_char(t_data *data, t_option *flag);
void			ft_str(t_data *data, t_option *flag);
void			ft_int(t_data *data, t_option *flag);
void			ft_uint(t_data *data, t_option *flag);
void			ft_double(t_data *data, t_option *flag);
void			ft_pint(t_data *data, t_option *flag);
void			ft_void(t_data *data, t_option *flag);
int				ft_intlen(long long int n);
long			ft_atoi1(t_format *fmtptr);
char			*ft_itoa1(long long n);
char			*ft_itoa2(double n);
void			space(char *exe, t_data *data, t_option *flag);
int				ft_pow(int nb, int pow);
char			*ft_itoa_base(int val, int base, int up);
void			stock_exe(t_data *data, char *txt, int len);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
void			ft_putchar(char c);
char			*ft_strcpy(char *dest, const char *src);
void			ft_putstr(char *str);

#endif
