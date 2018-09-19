/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:07:53 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/19 02:05:40 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	int r1 = 0, r2 = 0, x1 = 0, x2 = 0;
	r1 = 	printf("VR:: [%*s]\n", 25,"ma_printf");
	r2 = ft_printf("ME:: [%*s]\n", 25,"ma_printf");

	printf("[VR][%d] - [ME][%d]\n", r1, r2);

	printf("radhoin TEST:\n");
	x1 = 	printf("VR:: [%*%]\n",2);
	x2 = ft_printf("ME:: [%*%]\n",2);
	printf("[VR][%d] - [ME][%d]\n", x1, x2);
	return (0);
}
