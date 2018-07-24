/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 06:02:29 by bhamdi            #+#    #+#             */
/*   Updated: 2018/07/24 23:12:43 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(long n)
{
		int		i;

		i = 0;
		(n <= 0 ) ? i++ : i;
		n = (n < 0) ? (n * -1) : n;
		while (n > 0)
		{
				n /= 10;
				i++;
		}
		return (i);
}

int		ft_atoi1(t_format *fmtptr)
{
		int	i;
		int	result;
		int	sign;

		result = 0;
		sign = 0;
		i = 0;
		if (fmtptr->fmt[i] == '-')
				sign = 1;
		if (fmtptr->fmt[i] == '+' || fmtptr->fmt[i] == '-')
				i++;
		while (fmtptr->fmt[i] && fmtptr->fmt[i] >= '0' && fmtptr->fmt[i] <= '9')
		{
				result = (result * 10) + (fmtptr->fmt[i] - '0');
				i++;
		}
		if (sign == 1)
				return (-result);
		else
				return (result);
}

char	*ft_itoa1(long n)
{
		char	*ret;
		int		temp_n;
		size_t	size_ret;
		char	sign;

		sign = (n < 0) ? -1 : 1;
		size_ret = 2 + (n < 0);
		temp_n = n;
		while ((n = n / 10))
				size_ret++;
		n = temp_n;
		if ((ret = (char *)malloc(sizeof(char) * size_ret--)) == NULL)
				return (NULL);
		ret[size_ret--] = '\0';
		ret[size_ret--] = sign * (n % 10) + '0';
		while ((n = n / 10))
				ret[size_ret--] = sign * (n % 10) + '0';
		if (sign < 0)
				ret[size_ret] = '-';
		return (ret);
}
