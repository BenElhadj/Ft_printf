/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:00:38 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/17 18:39:41 by bhamdi           ###   ########.fr       */
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

	!flag->length && find("di", flag->speci) ? stock(data, 
			filling_i((data->type.exe_i = va_arg(*flag->argptr, int)), 
				data, flag), data->i) : 0;

	if (find("xX", flag->speci))
	{
		i = (flag->speci == 'X' ? 1: 0); 
		if (!flag->length)
		filling(ft_lltoa_base(va_arg(*flag->argptr, unsigned long), 16, i),
				data, flag);
	}


	(flag->length == 'h') && find("di", flag->speci) ? stock(data, 
			filling_i((data->type.exe_sh = (short)va_arg(*flag->argptr, int)), 
				data, flag), data->i) : 0;
	
	(flag->length == 'H') && find("di", flag->speci) ? stock(data, 
			filling_i((data->type.exe_c = (char)va_arg(*flag->argptr, int)), 
				data, flag), data->i) : 0;
	
	((flag->length == 'l') && find("di", flag->speci)) || (!flag->length &&
	flag->speci == 'D') ? stock(data, 
			filling_l((data->type.exe_l = va_arg(*flag->argptr, long)), 
				data, flag), data->i) : 0;
	
	(flag->length == 'L') && find("di", flag->speci) ? stock(data, 
			filling_ll((data->type.exe_ll = va_arg(*flag->argptr, long long)), 
				data, flag), data->i) : 0;
	
	(flag->length == 'j') && find("di", flag->speci) ? stock(data, 
			filling_im((data->type.exe_im = va_arg(*flag->argptr, intmax_t)), 
				data, flag), data->i) : 0;
	
	(flag->length == 'z') && find("di", flag->speci) ? stock(data, 
			filling_uint((data->type.exe_si = va_arg(*flag->argptr, size_t)), 
				data, flag), data->i) : 0;
	
	
	if (find("oO", flag->speci))
	{

		if (flag->length == 'L')
			data->type.exe_ull = ft_atoll(ft_lltoa_base((unsigned long long)
						va_arg(*flag->argptr, unsigned long long), 8, 0));
		else
			data->type.exe_ul = ft_atol(ft_lltoa_base((unsigned long)va_arg(
						*flag->argptr, unsigned long), 8, 0));
		flag->sharp && data->type.exe_ul ? stock(data, "0", 1): 0;
		stock(data, (filling_ul(data->type.exe_ul, data, flag)), data->i);
	}
}
