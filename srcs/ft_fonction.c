/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 06:02:29 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/11 01:46:08 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

char	*ft_itoa1(long long n)
{
	char			*ret;
	long long		temp_n;
	int				len;
	char			sign;

	sign = (n < 0) ? -1 : 1;
	len = 2 + (n < 0);
	temp_n = n;
	while ((n = n / 10))
		len++;
	n = temp_n;
	if ((ret = (char *)malloc(sizeof(char) * len--)) == NULL)
		return (NULL);
	ret[len--] = '\0';
	ret[len--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		ret[len--] = sign * (n % 10) + '0';
	if (sign < 0)
		ret[len] = '-';
	return (ret);
}
/*
char	*ft_itoa2(double n)
{
	char			*ret;
	long long		temp_n;
	int				len;
	char			sign;

	sign = (n < 0) ? -1 : 1;
	len = 2 + (n < 0);
	temp_n = n;
	while ((n = n / 10))
		len++;
	n = temp_n;
	if ((ret = (char *)malloc(sizeof(char) * len--)) == NULL)
		return (NULL);
	ret[len--] = '\0';
	ret[len--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		ret[len--] = sign * (n % 10) + '0';
	if (sign < 0)
		ret[len] = '-';
	return (ret);
}
*/
char	*ft_itoa3(unsigned long long n)
{
	char					*ret;
	unsigned long long		temp_n;
	int						len;

	len = 2;
	temp_n = n;
	while ((n = n / 10) ? len++ : 0);
	n = temp_n;
	if ((ret = (char *)malloc(sizeof(char) * len--)) == NULL)
		return (NULL);
	ret[len--] = '\0';
	ret[len--] = n % 10 + '0';
	while ((n = n / 10))
		ret[len--] = n % 10 + '0';
	return (ret);
}
