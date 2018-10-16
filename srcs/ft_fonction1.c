/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 01:32:25 by bhamdi            #+#    #+#             */
/*   Updated: 2018/10/16 14:43:43 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	char	*mall;
	char	*ret;
	char	c;

	i = 1;
	n = 0;
	up == 1 ? (c = 'A') : 0;
	up != 1 ? (c = 'a') : 0;
	if (val < 0)
		base == 10 ? ((n = 1) && (val *= -1)) : 0;
	while (ft_pow(base, i) - 1 < val)
		i++;
	if ((mall = (char*)malloc(sizeof(mall) * i)) == NULL)
		return (NULL);
	mall[i + n] = '\0';
	while (i-- > 0)
	{
		mall[i + n] = (val % base) + (val % base > 9 ? c - 10 : '0');
		val = val / base;
	}
	if (n)
		mall[0] = '-';
	ret = mall;
	free (mall);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mall;
	char	*ret;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = s1 ? ft_strlen(s1) : 0;
	len_s2 = s2 ? ft_strlen(s2) : 0;
	mall = (char *)malloc(sizeof(*mall) * (len_s1 + len_s2 + 1));
	if (s1)
		ft_strcpy(mall, s1);
	if (s2)
		ft_strcpy(mall + len_s1, s2);
	mall[len_s1 + len_s2] = '\0';
	ret = mall;
	free (mall);
	return (ret);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}
