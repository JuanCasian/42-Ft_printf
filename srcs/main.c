/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:42:24 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/02 15:46:13 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	unsigned long long int r;
	char *res;

	r = 100000000000;
	res = ft_utoabase(r, 15);
	printf("%s", res);
	return (0);
}
