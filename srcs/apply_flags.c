/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:32:10 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/03 15:03:14 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_flags(t_info *info)
{
	if (info->flags[Fhash] == 1)
	{
		if (info->speci == 'o' || info->speci == 'O')
			info->res = str_addprev("0", info->res);
		else if (info->speci == 'x')
			info->res = str_addprev("0x", info->res);
		else if (info->speci == 'X')
			info->res = str_addprev("0X", info->res);
	}
	else if (info->flags[Fspace] == 1 && info->flags[Fplus] != 1)
	{
		if ((info->speci == 'd' || info->speci == 'i' || info->speci == 'D')
				&& info->res[0] != '-')
			info->res = str_addprev(" ", info->res);
	}
	else if (info->flags[Fplus] == 1)
	{
		if ((info->speci == 'd' || info->speci == 'i' || info->speci == 'D')
				&& info->res[0] != '-')
			info->res = str_addprev("+", info->res);
	}
}
