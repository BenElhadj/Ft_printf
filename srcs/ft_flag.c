/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:53:26 by bhamdi            #+#    #+#             */
/*   Updated: 2018/08/02 05:50:37 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	filling(char *txt, char *exe, t_data *data, t_option *flag)
{
	int len;

	len = 0;
	while (exe[len])
		len++;
	if (flag->sign > 0 && (flag->sign -= len))
	{
		while (flag->sign > 0)
			stock(data, txt, 2) ? flag->sign-- : 0;
		stock(data, exe, len);
	}
	else if (flag->sign < 0 && (flag->sign += len))
	{
		stock(data, exe, len);
		while (flag->sign < 0)
			stock(data, txt, 2) ? flag->sign++ : 0;
	}
	else
		stock(data, exe, len);
}
