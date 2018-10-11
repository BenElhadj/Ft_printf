/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 03:51:41 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/11 03:34:00 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <fcntl.h>
# include <stdint.h>
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

typedef struct	s_type
{
	int					exe_i;
	short				exe_sh;
	char				exe_c;
	long				exe_l;
	long long			exe_ll;
	intmax_t			exe_im;
	size_t				exe_si;
	unsigned int		exe_ui;
	unsigned short		exe_ush;
	unsigned char		exe_uc;
	unsigned long		exe_ul;
	unsigned long long	exe_ull;
//	unsigned intmax_t	exe_uim;
	double				exe_d;
	long double			exe_ld;
	int					*exe_int;
	void				*exe_void;	
}				t_type;

typedef struct	s_data
{
	char		exe[SIZEBUF + 1];
	int			i;
		
	char		data[SIZEBUF + 1];
	size_t		index;
	size_t		len;
	t_type		type;
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
void			init_type(t_type *type);
void			apply_speci(t_data *data, t_option *flag);
void			flush_data(t_data *data);
int				stock(t_data *data, char *fmt, int len);
void			init_option(t_option *flag, va_list *args, int bt);
char			*filling_i(int exe, t_data *data, t_option *flag);
char			*filling_l(long exe, t_data *data, t_option *flag);
char			*filling_ll(long long exe, t_data *data, t_option *flag);
char			*filling_im(intmax_t exe, t_data *data, t_option *flag);
char			*filling_uint(unsigned int exe, t_data *data, t_option *flag);
char			*filling_ul(unsigned long exe, t_data *data, t_option *flag);
char			*filling_ull(unsigned long long exe, t_data *data, t_option 
					*flag);
void			filling(char *exe, t_data *data, t_option *flag);
void			ft_percent(t_data *data, t_option *flag);
void			ft_char(t_data *data, t_option *flag);
void			ft_str(t_data *data, t_option *flag);
void			ft_int(t_data *data, t_option *flag);
void			ft_uint(t_data *data, t_option *flag);
void			ft_double(t_data *data, t_option *flag);
void			ft_pint(t_data *data, t_option *flag);
void			ft_void(t_data *data, t_option *flag);
int				ft_intlen(unsigned long long n);
long			ft_atoi(char *str);
long			ft_atoi1(t_format *fmtptr);
char			*ft_itoa1(long long n);
char			*ft_itoa3(unsigned long long n);
//char			*ft_itoa2(double n);
void			space(char *exe, t_data *data, t_option *flag);
int				ft_pow(int nb, int pow);
char			*ft_itoa_base(int val, int base, int up);
void			stock_exe(t_data *data, char *txt, int len);
void			*ft_memset(void *b, long long c, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
void			ft_putchar(char c);
char			*ft_strcpy(char *dest, const char *src);
void			ft_putstr(char *str);

#endif
