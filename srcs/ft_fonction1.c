/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 01:32:25 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/19 01:35:25 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
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

void	ft_putendl(char const *s)
{
	char *str;

	str = (char*)s;
	if (str)
	{
		ft_putstr(str);
		ft_putchar('\n');
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = s1 ? ft_strlen(s1) : 0;
	len_s2 = s2 ? ft_strlen(s2) : 0;
	str = (char *)malloc(sizeof(*str) * (len_s1 + len_s2 + 1));
	if (s1)
		ft_strcpy(str, s1);
	if (s2)
		ft_strcpy(str + len_s1, s2);
	str[len_s1 + len_s2] = '\0';
	return (str);
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
