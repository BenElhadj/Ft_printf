/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:00:38 by bhamdi            #+#    #+#             */
/*   Updated: 2018/07/28 21:00:41 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%%
void	ft_percent(t_data *data/*, t_option *flag*/)
{
	char exe;
	
	exe = '%';
	stock(data, &exe, 1);
}

//%c
void	ft_char(t_data *data, t_option *flag)
{
	char exe[2];

	exe[0] = (char)va_arg(*flag->argptr, int);
	exe[1] = '\0';

	stock(data, exe, 2);
}

//%s
void	ft_str(t_data *data, t_option *flag)
{
	int len;

	len = 0;
	char *exe = (char*)va_arg(*flag->argptr, char*);
	while(exe[len])
		len++;

	stock(data, exe, len);
}

//%dioxX
void	ft_int(t_data *data, t_option *flag)
{
	int len;

	len = 0;
	int exe = va_arg(*flag->argptr, int);
	len = ft_intlen(exe);

	stock(data, ft_itoa1(exe), len);
}
