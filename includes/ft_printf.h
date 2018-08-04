/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:21:51 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/03 21:16:23 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <wchar.h>
# include <stdarg.h>
# include <locale.h>

# define NFLAGS 5
# define NLENGTHS 6
# define NSPECIS 14

typedef struct	s_info
{
	int		flags[NFLAGS];
	int		width;
	int		preci;
	int		lengths[NLENGTHS];
	char	speci;
	va_list	*args;
	char	**str;
	int		count;
	char	*res;
	wchar_t	*wres;
	int		leftpadded;
	int		zeropadded;
}				t_info;

enum			e_flags
{
	Fminus,
	Fplus,
	Fspace,
	Fhash,
	Fzero
};

enum			e_lengths
{
	Lhh,
	Lh,
	Ll,
	Lll,
	Lj,
	Lz
};

int				ft_printf(char *str, ...);
void			put_error(void);
void			reinit_struct(t_info *info);
void			check_flags(t_info *info);
void			check_widths(t_info *info);
void			check_precis(t_info *info);
void			check_lengths(t_info *info);
void			check_specis(t_info *info);
int				is_flag(char c);
int				is_width(char c);
int				is_preci(char c);
int				is_length(char c);
int				is_speci(char c);
void			get_andprint(t_info *info);
void			reinit_lengths(t_info *info);
void			check_lengthspt2(t_info *info);
char			*ft_itoalong(long long int n);
char			*ft_utoabase(unsigned long long int n,
		unsigned long long int base);
char			*address_tostr(unsigned long long int address);
char			*str_addprev(char *prefix, char *str);
char			*str_addsuf(char *suffix, char *str);
void			handle_gaddress(t_info *info);
void			ft_strtoupper(char **str);
void			handle_gsigneds(t_info *info);
void			handle_gunsigneds(t_info *info);
void			handle_gchars(t_info *info);
void			handle_gstrs(t_info *info);
char			*char_tostr(int c);
int				ft_putwchar(wchar_t c);
wchar_t			*ft_wstrnew(size_t size);
wchar_t			*ft_wstrdup(const wchar_t *s1);
wchar_t			*wchar_tostr(wchar_t c);
int				ft_wstrlen(wchar_t *wstr);
int				ft_wclen(wchar_t wc);
int				wchar_utf8(wchar_t wc, char	*convertion);
void			apply_flags(t_info *info);
void			apply_preci(t_info *info);
int				wchar_utf8len(wchar_t wc);
void			apply_width(t_info *info);
wchar_t			*wstr_addsuf(wchar_t *suffix, wchar_t *str);
wchar_t			*wstr_addprev(wchar_t *prefix, wchar_t *str);

#endif
