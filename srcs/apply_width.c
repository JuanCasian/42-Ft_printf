/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 18:17:20 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/03 19:29:18 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_widthpt3(t_info *info , int len)
{
	if (info->flags[Fminus] == 1)
	{
		while (len++ < info->width)
			info->res = str_addsuf(" ", info->res);
	}
	else
	{
		while (len++ < info->width)
			info->res = str_addprev(" ", info->res);
	}
}

void	apply_widthpt2(t_info *info)
{
	int len;
	int flag;

	flag = 0;
	len = ft_strlen(info->res);
	if (len >= info->width)
		return ;
	if ((info->speci != 's' || info->speci != 'S' || info->speci != 'p' ||
			info->speci != '%' || info->speci == 'c' || info->speci == 'C')
			&& info->flags[Fzero] == 1 && info->flags[Fminus] != 1
			&& info->preci < 0)
	{
		if (info->res[0] == '-' && info->width > len - 1)
		{
			info->res[0] = '0';
			info->width--;
			flag = 1;
		}
		while (len++ < info->width)
			info->res = str_addprev("0", info->res);
		if (flag == 1)
			info->res = str_addprev("-", info->res);
	}
	else
		apply_widthpt3(info, len);
}

void	apply_width(t_info *info)
{
	int len;

	if ((info->lengths[Ll] == 1 && (info->speci == 's' || info->speci == 'c'))
		|| info->speci == 'C' || info->speci == 'S')
	{
		len = ft_wstrlen(info->wres);
		if (len >= info->width)
			return ;
		while (info->flags[Fminus] == 1 && len++ < info->width)
			info->wres = wstr_addsuf(L" ", info->wres);
		while (info->flags[Fminus] != 1 && len++ < info->width)
			info->wres = wstr_addprev(L" ", info->wres);
	}
	else
		apply_widthpt2(info);
}
