/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:53:26 by bhamdi            #+#    #+#             */
/*   Updated: 2018/08/03 12:13:39 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	filling(char *txt, char *exe, t_data *data, t_option *flag)
{
	int len;
	long exe2;
	char *c;

	c = 0;
	(exe2 = ft_atoi(exe)) < 0 ? (exe = ft_itoa1(exe2 * -1)) && (c = "-\0") : 0;
	
//	printf("\nexe2 = [%ld]\n",exe2);
	len = 0;
	while (exe[++len]);
	flag->zero ? txt = "0\0" : 0;
// sign posetive
		if (flag->sign > 0 && (flag->sign -=  len + (flag->preci -= len) +
					(c ? 1 : 0)))
		{
			flag->space ? stock(data, " \0", 2) && flag->sign-- : 0;
			flag->plus ? flag->sign-- : 0;
			while (flag->sign > 0)
				stock(data, txt, 2) ? flag->sign-- : 0;
			flag->plus && (ft_atoi(exe) >= 0) ? stock(data, "+\0", 2) &&
				flag->sign-- : 0;
			c ? stock(data, c,2) && flag->sign-- && flag->preci-- : 0;
			while (flag->preci > 0)
				stock(data, "0\0", 2) ? flag->preci-- && flag->sign-- : 0;
			stock(data, exe, len);
		}
// sign negative
		else if (flag->sign < 0 && (flag->sign += (len >= flag->preci) ?
					flag->preci : len +2) + (c != 0 ? 1 : 0))
		{
			flag->preci -= len;
			flag->space ? stock(data, " \0", 2) && flag->sign++ : 0;
			flag->plus && (ft_atoi(exe) >= 0) ? stock(data, "+\0", 2) &&
				flag->sign++ : 0;
			c != 0 ? stock(data, c,2) && flag->sign++ && flag->preci-- : 0;
			while (flag->preci >= 0)
				stock(data, "0\0", 2) ? flag->preci-- && flag->sign++ : 0;
			stock(data, exe, len);
			while (flag->sign <= 0)
				stock(data, txt, 2) ? flag->sign++ : 0;
		}
		else
		{
			flag->preci -= len + (c ? 1 : 0);
			flag->space ? stock(data, " \0", 2) && flag->sign++ : 0;
			flag->plus && (ft_atoi(exe) >= 0) ? stock(data, "+\0", 2) &&
				flag->sign++ : 0;
			c ? stock(data, c,2) && flag->sign++ && flag->preci-- : 0;
			while (flag->preci >= 0)
				stock(data, "0\0", 2) ? flag->preci-- : 0;
			stock(data, exe, len);
		}
}
