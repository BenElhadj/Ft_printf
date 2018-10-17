/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 01:32:25 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/17 03:47:50 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa_base(int val, int base, int up)
{
	int			len;
	int			nbr;
	char		*ptr;
	char		*ret;
	char		*str;

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
