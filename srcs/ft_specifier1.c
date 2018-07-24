/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:00:38 by bhamdi            #+#    #+#             */
/*   Updated: 2018/07/24 22:52:07 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%%
void	ft_percent(t_data *data, t_option *flag)
{
	int exe = (int)va_arg(*flag->argptr, int);
	
	stock(data, ft_itoa1(exe), 1);
}

//%c
void	ft_char(t_data *data, t_option *flag)
{
	char exe = (char)va_arg(*flag->argptr, int);

	stock(data, ft_itoa1(exe), 1);
}

//%s
void	ft_str(t_data *data, t_option *flag)
{
	int len;

	len = 0;
	char *exe = va_arg(*flag->argptr, char*);
	while(exe[len])
		len++;

	stock(data, exe, len);
}

//%dioxX
void	ft_int(t_data *data, t_option *flag)
{
	int len;

	len = 0;
	int exe = (int)va_arg(*flag->argptr, int);
	len = ft_intlen(exe);

	stock(data, ft_itoa1(exe), len);
}
