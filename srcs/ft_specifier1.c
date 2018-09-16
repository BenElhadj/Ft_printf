/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:00:38 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/16 19:52:14 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *%%
 */

void	ft_percent(t_data *data, t_option *flag)
{
	char	exe;

	exe = '%';
	filling("%\0", data, flag);
}

/*
 *%c
 */

void	ft_char(t_data *data, t_option *flag)
{
	char	exe[2];

	exe[0] = (char)va_arg(*flag->argptr, int);
	exe[1] = '\0';
	
	filling(exe, data, flag);
}

/*
 *%s
 */

void	ft_str(t_data *data, t_option *flag)
{
	int		len;
	char	*exe;

	len = 0;
	exe = (char*)va_arg(*flag->argptr, char*);
//printf("\nexe = [%s]\n",exe);
	while (exe[len])
		len++;
	filling(exe, data, flag);
}

/*
 *%dioxX
 */

void	ft_int(t_data *data, t_option *flag)
{
//	int		len;
	int		exe;

//	len = 0;
	exe = va_arg(*flag->argptr, unsigned int);
	//filling_int(exe, data, flag);
	stock(data, filling_int(exe, data, flag), data->i);
}
