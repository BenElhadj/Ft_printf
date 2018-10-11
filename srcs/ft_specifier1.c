/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:00:38 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/11 15:40:20 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**%%
*/

void	ft_percent(t_data *data, t_option *flag)
{
	char	exe;

	exe = '%';
	filling("%\0", data, flag);
}

/*
**%c
*/

void	ft_char(t_data *data, t_option *flag)
{
	char	exe[2];

	exe[0] = (char)va_arg(*flag->argptr, int);
	//exe[0] == '\0' ? exe[0] == 0 : 0;
	exe[1] = '\0';
	filling(exe, data, flag);
}

/*
**%s
*/

void	ft_str(t_data *data, t_option *flag)
{
	int		len;
	char	*exe;

	len = 0;
	exe = (char*)va_arg(*flag->argptr, char*);
	exe == NULL ? exe = "(null)" : 0;
	while (exe[len])
		len++;
	filling(exe, data, flag);
}

/*
**%dDioOxX
*/

void	ft_int(t_data *data, t_option *flag)
{
	init_type(&data->type);

	!flag->length && find("dioOxX", flag->speci) ? stock(data, 
			filling_i((data->type.exe_i = va_arg(*flag->argptr, int)), 
				data, flag), data->i) : 0;

	if (!flag->length && find("oO", flag->speci))
	{
		data->type.exe_i = ft_atoi(ft_itoa_base(data->type.exe_i, 8, 0));
		stock(data, filling_i(data->type.exe_i, data, flag), data->i);
	}

	if (!flag->length && find("xX", flag->speci))
	{
		flag->speci == 'x' ? (data->type.exe_i = ft_atoi(ft_itoa_base(
					data->type.exe_i, 16, 0))) : (data->type.exe_i = ft_atoi(
					ft_itoa_base(data->type.exe_i, 16, 1)));
		filling_i(data->type.exe_i, data, flag);
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
	
	
/*	
	if (find("oO", flag->speci) || (find("ido", flag->speci)
				&& find("lL", flag->length)))
	{
		exe_int = va_arg(*flag->argptr, long long);
		flag->speci == 'o' ? exe_int = ft_atoi(ft_itoa_base(exe_int, 8, 0)) : 0;
		flag->speci == 'O' ? exe_int = ft_atoi(ft_itoa_base(exe_int, 8, 0)) : 0;

		stock(data, filling_int(exe_int, data, flag), data->i);
	}
	else if (flag->speci == 'x' || flag->speci == 'X')
		{
			exe = va_arg(*flag->argptr, int);
			flag->speci == 'x' ? (exe_char = ft_itoa_base(exe, 16, 0)) :
					 (exe_char = ft_itoa_base(exe, 16, 1));
			filling(exe_char, data, flag);
		}
	else
	{
		stock(data, filling_int((exe = va_arg(*flag->argptr, int)),
					data, flag), data->i);
	}
	exe_char ? (free(exe_char)) : 0;*/
}
