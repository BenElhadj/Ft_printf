/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:00:38 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/16 18:14:03 by bhamdi           ###   ########.fr       */
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
	init_type(&data->type);

	!flag->length && find("di", flag->speci) ? stock(data, 
			filling_i((data->type.exe_i = va_arg(*flag->argptr, int)), 
				data, flag), data->i) : 0;

	if (find("oO", flag->speci))
	{
		if (!flag->length)
		{
			data->type.exe_ll = va_arg(*flag->argptr, long long);
			data->type.exe_ll = ft_atoi(ft_lltoa_base(data->type.exe_ll, 8, 0));
			flag->sharp && data->type.exe_ll ? stock(data, "0", 1): 0;
			stock(data, filling_ll(data->type.exe_ll, data, flag), data->i);
		}
		else if (flag->length == 'H')
		{
			data->type.exe_l = (char)va_arg(*flag->argptr, int);
			data->type.exe_c = ft_atoi(ft_lltoa_base(data->type.exe_l, 8, 0));
			flag->sharp && data->type.exe_c ? stock(data, "0", 1): 0;
			stock(data, filling_ll(data->type.exe_c, data, flag), data->i);
		}
	}

	
	if (!flag->length && find("xX", flag->speci))
	{
		data->type.exe_i = (unsigned int)va_arg(*flag->argptr, unsigned int);
		flag->speci == 'x' ? (data->type.exe_str = ft_itoa_base(data->type.exe_i
					, 16, 0)) : (data->type.exe_str = ft_itoa_base(
						data->type.exe_i, 16, 1));
		filling(data->type.exe_str, data, flag);
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
	
	
}
