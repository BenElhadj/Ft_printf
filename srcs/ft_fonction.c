/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 06:02:29 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/18 11:05:57 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long	ft_atol_t(t_format *fmtptr)
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

char	*ft_lltoa(long long n)
{
	char			*mall;
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
	if ((mall = (char *)malloc(sizeof(char) * len--)) == NULL)
		return (NULL);
	mall[len--] = '\0';
	mall[len--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		mall[len--] = sign * (n % 10) + '0';
	if (sign < 0)
		mall[len] = '-';
	ret = mall;
	free (mall);
	return (ret);
}

char	*ft_ulltoa(unsigned long long n)
{
	char					*mall;
	char					*ret;
	unsigned long long		temp_n;
	int						len;

	len = 2;
	temp_n = n;
	while ((n = n / 10) ? len++ : 0);
	n = temp_n;
	if ((mall = (char *)malloc(sizeof(char) * len--)) == NULL)
		return (NULL);
	mall[len--] = '\0';
	mall[len--] = n % 10 + '0';
	while ((n = n / 10))
		mall[len--] = n % 10 + '0';
	ret = mall;
	free (mall);
	return (ret);
}

char	*ft_lltoa_base(unsigned long long val, long base, int up)
{
	int64_t				len;
	unsigned long long	nbr;
	char				*ptr;
	char				*ret;
	char				*str;

	up == 1 ? (str = "0123456789ABCDEF") : (str = "0123456789abcdef");
	if (val == 0)
		return ("0");
	len = 0;
	nbr = val;
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	nbr = val;
	if (!(ptr = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ptr[len] = '\0';
	while (nbr)
	{
		ptr[--len] = str[nbr % base];
		nbr /= base;
	}
	ret = ptr;
	free (ptr);
	return (ret);
} 
