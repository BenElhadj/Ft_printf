/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 01:32:25 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/17 15:22:29 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long		ft_atol(char *str)
{
	int		i;
	long	result;
	int		sign;

	result = 0;
	sign = 0;
	i = 0;
	if (!str)
		return(0);
	while ((str[i] == '\n') || (str[i] == '\t') ||
			(str[i] == '\v') || (str[i] == ' ') ||
			(str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (sign == 1)
		return (-result);
	else
		return (result);
}

long long		ft_atoll(char *str)
{
	long long	result;
	int			sign;
	long		i;

	result = 0;
	sign = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') ||
			(str[i] == '\v') || (str[i] == ' ') ||
			(str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (sign == 1)
		return (-result);
	else
		return (result);
}
