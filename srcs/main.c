/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:07:53 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/17 11:44:07 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	int r1 = 0, r2 = 0, x1 = 0, x2 = 0;
	r1 = 	printf("VR:: [%s]\n", "ma_printf");
	r2 = ft_printf("ME:: [%s]\n", "ma_printf");

	printf("[VR][%d] - [ME][%d]\n", r1, r2);

	printf("radhoin TEST:\n");
	x1 = 	printf("VR:: [%*c]\n",5,'A');
	x2 = ft_printf("ME:: [%*c]\n",5,'A');
	printf("[VR][%d] - [ME][%d]\n", x1, x2);
	return (0);
}
