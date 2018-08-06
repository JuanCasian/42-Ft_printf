/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:15:50 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/06 14:18:51 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_widthwchar(t_info *info)
{
	int len;

	if (info->width > (len = ft_wstrlen(info->wres)))
	{
		while (info->flags[Fminus] == 1 && info->width > len)
		{
			info->wres = ft_wstraddsuffix(L" ", info->wres);
			len++;
		}
		while (info->flags[Fzero] == 1 && info->width > len)
		{
			info->wres = ft_wstraddprefix(L"0", info->wres);
			len++;
		}
		while (info->width > len)
		{
			info->wres = ft_wstraddprefix(L" ", info->wres);
			len++;
		}
	}
}

static void	apply_width(t_info *info)
{
	int len;

	if (info->speci == 'c' && info->lens[Ll] != 1)
	{
		if (info->width > (len = ft_strlen(info->res)))
		{
			while (info->flags[Fminus] == 1 && info->width > len)
			{
				info->res = ft_straddsuffix(" ", info->res);
				len++;
			}
			while (info->flags[Fzero] == 1 && info->width > len)
			{
				info->res = ft_straddprefix("0", info->res);
				len++;
			}
			while (info->width > len)
			{
				info->res = ft_straddprefix(" ", info->res);
				len++;
			}
		}
	}
	else
		apply_widthwchar(info);
}

void		prepare_char(t_info *info)
{
	if (info->speci == 'c' && info->lens[Ll] != 1)
	{
		if (!(info->res = ft_strnew(1)))
			print_error();
		info->res[0] = va_arg(info->args[0], int);
	}
	else
	{
		if (!(info->wres = ft_wstrnew(1)))
			print_error();
		info->wres[0] = va_arg(info->args[0], wchar_t);
	}
	if (info->width > 0)
		apply_width(info);
}
