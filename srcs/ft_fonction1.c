/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 01:32:25 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/05 11:16:07 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_memset(void *b, long long c, size_t len)
{
	char *str;

	str = (char*)b;
	while (len--)
	{
		*str = (char)c;
		str++;
	}
	return (b);
}

size_t	ft_strlen(const char *str)
{
	int64_t i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int		ft_intlen(unsigned long long n)
{
	int		i;

	i = 0;
	n <= 0 ? i++ : 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
