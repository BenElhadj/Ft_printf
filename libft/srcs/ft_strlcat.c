/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 05:42:26 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/24 12:52:54 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	ndest;
	size_t	nsrc;
	size_t	i;

	ndest = ft_strlen(dest);
	nsrc = ft_strlen((char*)src);
	if (size == 0)
		return (nsrc);
	i = 0;
	while (src[i] && (ndest + i) < (size - 1))
	{
		dest[ndest + i] = src[i];
		i++;
	}
	dest[ndest + i] = '\0';
	if (ndest < size)
		return (nsrc + ndest);
	return (nsrc + size);
}
