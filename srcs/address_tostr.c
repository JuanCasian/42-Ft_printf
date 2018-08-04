/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_tostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 18:53:28 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/03 21:15:21 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*address_tostr(unsigned long long int address)
{
	char *res;

	res = ft_utoabase(address, 16);
	res = str_addprev("0x", res);
	return (res);
}
