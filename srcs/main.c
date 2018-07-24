/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:07:53 by bhamdi            #+#    #+#             */
/*   Updated: 2018/07/22 16:16:38 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int i;
//	void	*ptr;
	i = 0;

	i = ft_printf("{je commence %-17d\n====> %+11d\n====> % %\nbhamdi.%-9d...???.ben. %*.15lld,.elhadj.%+9hhs}%*%", "1303", "1952", "1108", "MY MOM", "RACHIDA IN MY HEART", "allah yar7emha.", "%");
//	printf("\n\n<<<(je commence %%*.17LD\n====> %%%%\n====> %%1.4%%\nbhamdi.%%- 19hhd ...???.ben. %%*.15    lld,.elhadj.%%.*hhs}%%*%%\", \"MY MOM\", \"1952\", \"RACHIDA IN MY HEART\", \"13,03\", \"11,0    8\", \"allah yar7emha\", \"%%\")>>>");
	//ptr = "salut";
	printf("\nft_printf return(%d)", i);
//	printf("\nft_printf d(% 5d)", -12);
	//printf("\nft_printf return(%p)", ptr);
	return (0);
}
