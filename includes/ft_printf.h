/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:21:51 by jcasian           #+#    #+#             */
/*   Updated: 2018/07/31 20:23:52 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define NFLAGS 5
# define NWIDTHS 2
# define NPRECIS 2
# define NLENGTHS 2
# define NSPECIS 14

typedef struct	s_info
{
	int		flags[NFLAGS];
	int		widths[NWIDTHS];
	int		precis[NPRECIS];
	int		lengths[NLENGTHS];
	int		specis[NSPECIS];
	va_list	*args;
	char	**str;
	int		count;
}				t_info;

enum			e_flags
{
	Fminus,
	Fplus,
	Fspace,
	Fhash,
	Fzero
};

enum			e_widths
{
	Wnumber,
	Waster
};

enum			e_precis
{
	Pnumber,
	Paster
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

enum			e_specis
{
	Sper,
	Ss,
	SS,
	Sp,
	Sd,
	SD,
	Si,
	So,
	SO,
	Su,
	SU,
	Sx,
	SX,
	Sc,
	SC
};

int				ft_printf(char *str, ...);
void			reinit_struct(t_info *info);
void			check_flags(t_info *info);
void			check_widths(t_info *info);
void			check_precis(t_info *info);
void			check_lengths(t_info *info);
void			check_specis(t_info *info);
void			print_var(t_info *info);
int				is_flag(char c);
int				is_width(char c);
int				is_preci(char c);
int				is_length(char c);
int				is_speci(char c);

#endif
