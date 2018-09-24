/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revwstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:01:41 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/24 12:01:43 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	revwstr(char *s)
{
	int	i;
	int	start;

	i = 0;
	while (s[i] && ft_space(s[i]))
		i++;
	if (!s[i])
		return ;
	start = i;
	while (s[i] && !ft_space(s[i]))
		i++;
	revwstr(&s[i]);
	write(1, &s[start], i - start);
	if (start > 0)
		write(1, " ", 1);
}
