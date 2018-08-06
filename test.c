/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 18:41:50 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/05 17:26:16 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include "ft_printf.h"

int		main(void)
{
	int	k;
	int j;

	long r;
	wchar_t *s;

	s = ft_wstrdup(L"HELLOOO");
	s[3] = 0x1F601;
	r = 9;

	setlocale(LC_ALL, "");
	j  = ft_printf("YOURS: %0 10lld\n",(long long int)r);
	printf("YOURS: %i\n", j);
	setlocale(LC_ALL, "");
	k  = printf("REAL#: %0 10lld\n", (long long int)r);
	printf("REAL#: %i\n", k);
	return (0);
}
