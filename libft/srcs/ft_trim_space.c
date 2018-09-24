/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:04:41 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/24 12:04:43 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_trim_space(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}