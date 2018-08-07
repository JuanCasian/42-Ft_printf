/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 18:41:50 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/06 18:25:12 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include "ft_printf.h"

int		main(void)
{
	int j;

	setlocale(LC_ALL, "");
	ft_printf("------- My own printf function test -------\n");
	ft_printf("ft_printf result: ");
	j = ft_printf("%C", L'😀');
	ft_printf("\n");
	ft_printf("Number of characters printed in test: %i\n", j);
	return (0);
}
