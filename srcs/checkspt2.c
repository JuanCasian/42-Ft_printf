/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lengthspt2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 15:41:30 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/03 21:13:53 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_lengthspt2(t_info *info)
{
	if (info->str[0][0] == 'l')
	{
		if (info->str[0][1] == 'l')
		{
			reinit_lengths(info);
			info->lengths[Lll] = 1;
			(info->str[0])++;
		}
		else
		{
			reinit_lengths(info);
			info->lengths[Ll] = 1;
		}
	}
	else if (info->str[0][0] == 'z')
	{
		reinit_lengths(info);
		info->lengths[Lz] = 1;
	}
}
