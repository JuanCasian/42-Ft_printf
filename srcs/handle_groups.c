/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_groups.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 19:59:19 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/03 19:42:09 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_gsigneds(t_info *info)
{
	if (info->lengths[Lhh] == 1 && info->speci != 'D')
		info->res = ft_itoalong((long long int)va_arg(info->args[0],
					int));
	else if (info->lengths[Lh] == 1 && info->speci != 'D')
		info->res = ft_itoalong((long long int)va_arg(info->args[0],
					int));
	else if (info->lengths[Ll] == 1 && info->speci != 'D')
		info->res = ft_itoalong((long long int)va_arg(info->args[0],
					long int));
	else if (info->lengths[Lll] == 1 ||  info->speci == 'D')
		info->res = ft_itoalong(va_arg(info->args[0],
					long long int));
	else if (info->lengths[Lj] == 1 && info->speci != 'D')
		info->res = ft_itoalong((long long int)va_arg(info->args[0],
					intmax_t));
	else if (info->lengths[Lz] == 1 && info->speci != 'D')
		info->res = ft_utoabase((unsigned long long int)va_arg(info->args[0],
					size_t), 10);
	else
		info->res = ft_itoalong((long long int)va_arg(info->args[0],
					int));
}

void	handle_gunsigneds(t_info *info)
{
	if (info->speci == 'U' || info->speci == 'u')
		info->res = ft_utoabase(va_arg(info->args[0], unsigned long long int), 10);
	else if (info->speci == 'o' || info->speci == 'O')
		info->res = ft_utoabase(va_arg(info->args[0], unsigned long long int), 8);
	else if (info->speci == 'x' || info->speci == 'X')
		info->res = ft_utoabase(va_arg(info->args[0], unsigned long long int), 16);
	else if (info->speci == 'b')
		info->res = ft_utoabase(va_arg(info->args[0], unsigned long long int), 2);
	if (info->speci == 'X' || info->speci == 'O')
		ft_strtoupper(&info->res);
}

void	handle_gchars(t_info *info)
{
	if (info->lengths[Ll] == 1 || info->speci == 'C')
		info->wres = wchar_tostr(va_arg(info->args[0], wchar_t));
	else
		info->res = char_tostr(va_arg(info->args[0], int));
}

void	handle_gstrs(t_info *info)
{
	char 	*str;
	wchar_t *wstr;

	if (info->lengths[Ll] == 1 || info->speci == 'S')
	{
		if (!(wstr = va_arg(info->args[0], wchar_t*)))
			info->wres = ft_wstrdup(L"(null)");
		else
			info->wres = ft_wstrdup(wstr);
	}
	else
	{
		if (!(str = va_arg(info->args[0], char*)))
			info->res = ft_strdup("(null)");
		else
			info->res = ft_strdup(str);
	}
}

void	handle_gaddress(t_info *info)
{
	info->res = ft_utoabase(va_arg(info->args[0],
				unsigned long long int), 16);
	if (info->speci == 'P')
		ft_strtoupper(&info->res);
	info->res = str_addprev("0x", info->res);
}
