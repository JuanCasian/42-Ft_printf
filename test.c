/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 18:41:50 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/05 14:08:24 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include "ft_printf.h"

int		main(void)
{
	int	k;
	int j;

	wchar_t *s;

	s = ft_wstrdup(L"HELLOOO");
	s[3] = 0x1F601;

	setlocale(LC_ALL, "");
	j  = ft_printf("YOURS: %30.20p\n", (void*)&s);
	printf("YOURS: %i\n", j);
	setlocale(LC_ALL, "");
	k  = printf("REAL#: %30.20p\n", (void*)&s);
	printf("REAL#: %i\n", k);
	return (0);
}
