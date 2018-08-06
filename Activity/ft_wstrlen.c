/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 20:51:30 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/04 20:52:47 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wstrlen(wchar_t *wstr)
{
	int	i;
	int len;

	i = 0;
	len = 0;
	while (wstr[i])
	{
		len += ft_wchar_len(wstr[i]);
		i++;
	}
	return (len);
}
