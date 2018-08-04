/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr_addprev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 18:34:53 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/03 21:11:40 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*wstr_addprev(wchar_t *prefix, wchar_t *str)
{
	int		i;
	int		j;
	wchar_t	*res;

	j = 0;
	i = 0;
	while (prefix[i])
		i++;
	while (str[j++])
		i++;
	if (!(res = ft_wstrnew(i)))
		put_error();
	j = -1;
	while (prefix[++j])
		res[j] = prefix[j];
	i = 0;
	while (str[i])
	{
		res[j++] = str[i];
		i++;
	}
	free(str);
	return (res);
}

wchar_t	*wstr_addsuf(wchar_t *suffix, wchar_t *str)
{
	int		i;
	int		j;
	wchar_t	*res;

	j = 0;
	i = 0;
	while (suffix[i])
		i++;
	while (str[j++])
		i++;
	if (!(res = ft_wstrnew(i)))
		put_error();
	j = -1;
	while (str[++j])
		res[j] = str[j];
	i = 0;
	while (suffix[i])
	{
		res[j++] = suffix[i];
		i++;
	}
	free(str);
	return (res);
}
