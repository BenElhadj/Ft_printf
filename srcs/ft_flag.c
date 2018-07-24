/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:53:26 by bhamdi            #+#    #+#             */
/*   Updated: 2018/07/23 20:52:56 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	space(char *exe, t_data *data, t_option *flag)
{
	filling(" \0", exe, data, flag);
}

void	filling(char *txt, char *exe, t_data *data, t_option *flag)
{
	int len;

	len = 0;
	while (exe[len])
		len++;
	if (flag->left)
	{
		flag->left -= len;
		while (flag->left > 0)
		{
			txt ? stock(data, txt, 2) : stock(data, " \0", 2);
			flag->left--;
		}
		stock(data, exe, len);
	}
	else if (flag->sign)
	{
		stock(data, exe, len);
		flag->sign -= len;
		while (flag->sign > 0)
		{
			txt ? stock(data, txt, 2) : stock(data, " \0", 2);
			flag->sign--;
		}
	}
}
