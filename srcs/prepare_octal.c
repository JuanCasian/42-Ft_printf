/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 15:19:15 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/05 16:49:45 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void apply_hash(t_info *info, int flag)
{
	if (info->flags[Fhash] == 1)
	{
		if (((info->flags[Fzero] != 1 || info->flags[Fminus] == 1) &&
				flag == 0) || (info->flags[Fzero] == 1 && info->preci > 0
					&& flag == 0))
			info->res = ft_straddprefix("0", info->res);
	}
}

static void	apply_width(t_info *info)
{
	int len;

	if (info->width > (len = ft_strlen(info->res)))
	{
		while (info->flags[Fminus] == 1 && len < info->width)
		{
			info->res = ft_straddsuffix(" ", info->res);
			len++;
		}
		if (info->flags[Fzero] == 1 && info->flags[Fminus] != 1 &&
				info->flags[Fhash] == 1 && info->preci < 0)
			len += 1;
		while (info->flags[Fzero] == 1 && len < info->width &&
				info->preci < 0)
		{
			info->res = ft_straddprefix("0", info->res);
			len++;
		}
		while (len < info->width)
		{
			info->res = ft_straddprefix(" ", info->res);
			len++;
		}
	}
	apply_hash(info, 1);
}

static void	apply_precision(t_info *info)
{
	int len;

	apply_hash(info, 0);
	if (info->preci > (len = ft_strlen(info->res)))
	{
		while (info->preci > len)
		{
			info->res = ft_straddprefix("0", info->res);
			len++;
		}
	}
}

void		prepare_octal(t_info *info)
{
	if (info->lens[Lhh] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned int), 8);
	else if (info->lens[Lh] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned int), 8);
	else if (info->lens[Ll] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned long int), 8);
	else if (info->lens[Lll] == 1)
		info->res = ft_utoabaselonglong(va_arg(info->args[0],
					unsigned long long int), 8);
	else if (info->lens[Lj] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], uintmax_t), 8);
	else if (info->lens[Lz] == 1)
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], size_t), 8);
	else
		info->res = ft_utoabaselonglong((unsigned long long int)va_arg(
					info->args[0], unsigned int), 8);
	apply_precision(info);
	apply_width(info);
	if (info->speci == 'O')
		ft_strtoupper(&info->res);
}
