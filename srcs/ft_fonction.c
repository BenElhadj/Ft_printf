/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 06:02:29 by bhamdi            #+#    #+#             */
/*   Updated: 2018/07/31 21:23:48 by bhamdi           ###   ########.fr       */
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

long	ft_atoi1(t_format *fmtptr)
{
	long	result;
	long	sign;

	result = 0;
	sign = 0;
	if (fmtptr->fmt[fmtptr->i] == '-')
		sign = 1;
	if (fmtptr->fmt[fmtptr->i] == '+' || fmtptr->fmt[fmtptr->i] == '-')
		fmtptr->i++;
	while (fmtptr->fmt[fmtptr->i] && fmtptr->fmt[fmtptr->i] >= '0' &&
		fmtptr->fmt[fmtptr->i] <= '9')
	{
		result = (result * 10) + (fmtptr->fmt[fmtptr->i] - '0');
		fmtptr->i++;
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
	int		size_ret;
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

int		ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char	*ft_itoa_base(int val, int base, int up)
{
	int		i;
	int		n;
	char	*nbr;
	char	c;

	i = 1;
	n = 0;
	up == 1 ? (c = 'A'): (c = 'a');
		if (val < 0)
			base == 10 ? ((n = 1) && (val *= -1)) : 0;
	while (ft_pow(base, i) - 1 < val)
		i++;
	if ((nbr = (char*)malloc(sizeof(nbr) * i)) == NULL)
		return (NULL);
	nbr[i + n] = '\0';
	while (i-- > 0)
	{
		nbr[i + n] = (val % base) + (val % base > 9 ? c - 10 : '0');
		val = val / base;
	}
	if (n)
		nbr[0] = '-';
	return (nbr);
}
