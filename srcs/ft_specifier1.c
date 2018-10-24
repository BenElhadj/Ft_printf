/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:00:38 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/24 21:52:51 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**%%
*/

void	ft_percent(t_data *data, t_option *flag)
{
	filling("%\0", data, flag);
}

/*
**%c
*/

void	ft_char(t_data *data, t_option *flag)
{
	char	exe[2];

	exe[0] = (char)va_arg(*flag->argptr, int);
	exe[1] = '\0';
	filling(exe, data, flag);
}

/*
**%s
*/

void	ft_str(t_data *data, t_option *flag)
{
	char	*exe;

	exe = (char*)va_arg(*flag->argptr, char*);
	filling(exe, data, flag);
}

/*
**%dDioOxX
*/

void	ft_int(t_data *data, t_option *flag)
{
	int i;

	init_type(&data->type);

	
	if (find("xX", flag->speci))
	{
		i = (flag->speci == 'X' ? 1: 0);
	
		!flag->length ? filling_x(ft_lltoa_base((unsigned long)va_arg
				(*flag->argptr, unsigned long), 16, i), data, flag) : 0;

		flag->length == 'h' ? filling_x(ft_lltoa_base((short)va_arg
				(*flag->argptr, int), 16, i), data, flag) : 0;

		flag->length == 'H' ? filling_x(ft_lltoa_base((char)va_arg
				(*flag->argptr, int), 16, i), data, flag) : 0;

		flag->length == 'l' ? filling_x(ft_lltoa_base((long)va_arg
				(*flag->argptr, long), 16, i), data, flag) : 0;

		flag->length == 'L' ? filling_x(ft_lltoa_base((long long)va_arg
				(*flag->argptr, long long), 16, i), data, flag) : 0;

		flag->length == 'j' ? filling_x(ft_lltoa_base((intmax_t)va_arg
				(*flag->argptr, intmax_t), 16, i), data, flag) : 0;

		flag->length == 'z' ? filling_x(ft_lltoa_base((size_t)va_arg
				(*flag->argptr, size_t), 16, i), data, flag) : 0;

	}


	else if (find("oO", flag->speci))
	{
		!flag->length ? filling_o(ft_lltoa_base((unsigned long)va_arg
			(*flag->argptr, unsigned long), 8, 0), data, flag): 0;
		(flag->length == 'h') ? filling_o(ft_lltoa_base((unsigned short)va_arg
			(*flag->argptr, unsigned int), 8, 0), data, flag): 0;
		(flag->length == 'H') ? filling_o(ft_lltoa_base((unsigned char)va_arg
			(*flag->argptr, unsigned int), 8, 0), data, flag): 0;
		(flag->length == 'l') || (flag->speci == 'D') ? filling_o(ft_lltoa_base
			((long long)va_arg(*flag->argptr, long long), 8, 0), data, flag): 0;
		(flag->length == 'L') ? filling_o(ft_lltoa_base((unsigned long long)
			va_arg(*flag->argptr, unsigned long long), 8, 0), data, flag): 0;
		(flag->length == 'j') ? filling_o(ft_lltoa_base((intmax_t)va_arg
			(*flag->argptr, intmax_t), 8, 0), data, flag): 0;
		(flag->length == 'z') ? filling_o(ft_lltoa_base((size_t)va_arg
			(*flag->argptr, size_t), 8, 0), data, flag): 0;
	}


	else if (find("dDi", flag->speci))
	{

		(!flag->length && !(flag->speci == 'D')) ? stock(data,filling_i((data->
			type.exe_i = va_arg(*flag->argptr, int)),data, flag), data->i) : 0;
		(flag->length == 'h' && !(flag->speci == 'D')) ? stock(data,
			filling_i((data->type.exe_sh = (short)va_arg(*flag->argptr, int)),
				data, flag), data->i) : 0;
		(flag->length == 'H' && !(flag->speci == 'D')) ? stock(data, filling_i(
				(data->type.exe_c = (char)va_arg(*flag->argptr, int)), data,
					flag), data->i) : 0;
		(flag->length == 'l' || flag->speci == 'D') ? stock(data,filling_l((
				data->type.exe_l = va_arg(*flag->argptr, long)), data, flag),
					data->i) : 0;
		(flag->length == 'L' && !(flag->speci == 'D')) ? stock(data, filling_ll
				((data->type.exe_ll = va_arg(*flag->argptr, long long)),
				 	data, flag), data->i) : 0;
		(flag->length == 'j' && !(flag->speci == 'D')) ? stock(data, filling_im
				((data->type.exe_im = va_arg(*flag->argptr, intmax_t)), data,
				 	flag), data->i) : 0;
		(flag->length == 'z' && !(flag->speci == 'D')) ? stock(data,
				filling_uint((data->type.exe_si = va_arg(*flag->argptr,
					size_t)), data, flag), data->i) : 0;
	}
}
