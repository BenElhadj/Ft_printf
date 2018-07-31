/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:53:26 by bhamdi            #+#    #+#             */
/*   Updated: 2018/07/31 21:46:12 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void	space(char *exe, t_data *data, t_option *flag)
{
	filling(" \0", exe, data, flag);
}
*/
void	filling(char *txt, char *exe, t_data *data, t_option *flag)
{
	int len;
	
	len = 0;
	while (exe[len])
		len++;
//	printf("\nflag->sign > = [%d]\n",flag->sign);
	if (flag->sign > 0 && (flag->sign -= len))
	{
	
		while (flag->sign > 0)
		{
			stock(data, txt, 2);
			flag->sign--;
		}
		stock(data, exe, len);
	}
	else if (flag->sign < 0 && (flag->sign += len))
	{
		stock(data, exe, len);
		while (flag->sign < 0)
		{
			stock(data, txt, 2);
			flag->sign++;
		}
	}
	else
		stock(data, exe, 2);
}
