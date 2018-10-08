/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:07:53 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/28 03:42:58 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

int		main(void)
{
	int r1 = 0, r2 = 0, x1 = 0, x2 = 0;
	r1 = 	printf("VR:: [%lli]\n", (long long)0x11ff11ff11ff11ff);
	r2 = ft_printf("ME:: [%lli]\n", (long long)0x11ff11ff11ff11ff);

	printf("[VR][%d] - [ME][%d]\n", r1, r2);

	printf("radhoin TEST:\n");
	x1 = 	printf("VR:: [% -20.17d]\n",42);
	x2 = ft_printf("ME:: [% -20.17d]\n",42);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);
	return (0);
}
