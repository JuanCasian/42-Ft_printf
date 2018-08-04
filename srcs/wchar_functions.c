/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 12:59:40 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/03 21:01:45 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putwchar(wchar_t c)
{
	int		len;
	char	convertion[4];

	len = wchar_utf8(c, convertion);
	write(1, convertion, len);
	return (len);
}

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t	*wstr;
	size_t	i;

	i = 0;
	wstr = (wchar_t*)malloc(sizeof(wchar_t) * size + 1);
	if (!wstr)
		return (NULL);
	while (i <= size)
	{
		wstr[i] = '\0';
		i++;
	}
	return (wstr);
}

wchar_t	*ft_wstrdup(const wchar_t *s1)
{
	wchar_t *wres;
	int		i;

	i = -1;
	if (!(wres = (wchar_t*)malloc(sizeof(wchar_t) * ft_wstrlen((wchar_t*)
						s1) + 1)))
		return (NULL);
	while (s1[++i])
		wres[i] = s1[i];
	wres[i] = '\0';
	return (wres);
}

wchar_t	*wchar_tostr(wchar_t c)
{
	wchar_t	*wres;

	wres = ft_wstrnew(2);
	wres[0] = c;
	return (wres);
}

int		ft_wstrlen(wchar_t *wstr)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (wstr[i])
	{
		len += wchar_utf8len(wstr[i]);
		i++;
	}
	return (len);
}
