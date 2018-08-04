/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_preci.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 15:05:18 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/03 18:15:19 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_precipt2(t_info *info)
{
	int len;
	int flag;

	flag = 0;
	if ((info->speci == 'U' || info->speci == 'u' || info->speci == 'o' ||
			info->speci == 'x' || info->speci == 'X' || info->speci == 'O' ||
			info->speci == 'b' ) && (len = ft_strlen(info->res)))
	{
		while (len++ < info->preci)
			info->res = str_addprev("0", info->res);
	}
	else if (info->speci == 'I' || info->speci == 'i' || info->speci == 'D')
	{
		len = ft_strlen(info->res);
		if (info->res[0] == '-' && info->preci > len - 1)
		{
			info->res[0] = '0';
			info->speci--;
			flag = 1;
		}
		while (len++ < info->preci)
			info->res = str_addprev("0", info->res);
		if (flag == 1)
			info->res = str_addprev("-", info->res);
	}
}

void		apply_preci(t_info *info)
{
	int len;
	int i;

	len = 0;
	i = -1;
	if (info->preci >= 0)
	{
		if ((info->lengths[Ll] == 1 && info->speci == 's') || info->speci == 'S')
		{
			while (len < info->preci && info->wres[++i])
				len += wchar_utf8len(info->wres[i]);
			if (info->wres[i])
				info->wres[i] = L'\0';
		}
		else if (info->speci == 's')
		{
			i = 0;
			while (info->res[i] && i < info->preci)
				i++;
			if (info->res[i])
				info->res[i] = '\0';
		}
		else
			apply_precipt2(info);
	}
}
