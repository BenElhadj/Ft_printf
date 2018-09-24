/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 22:08:00 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/24 13:05:28 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, char *to_find, size_t n)
{
	size_t	len;

	len = ft_strlen(to_find);
	if (*to_find == '\0')
		return ((char *)str);
	while (*str != '\0' && n-- >= len)
	{
		if (*str == *to_find && ft_memcmp(str, to_find, len) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
