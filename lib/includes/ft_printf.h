/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 21:40:09 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/05 18:12:11 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

typedef struct		s_lst
{
	char			*flags;
	char			*lenmod;
	char			*conv;
	char			*str_saved;
	char			*w_save;
	int				len_read;
	int				precision;
	int				lenp;
	int				point;
	int				neg;
	int				str_len;
}					t_arg;

typedef struct		s_w
{
	unsigned int	mask_1;
	unsigned int	mask_2;
	unsigned int	mask_3;
	unsigned int	ret;
	int				size;
	unsigned char	octet;
	unsigned char	oct_1;
	unsigned char	oct_2;
	unsigned char	oct_3;
	unsigned char	oct_4;

}					t_w;

int					ft_printf(const char *format, ...);
int					searchp(const char *format, va_list args);
int					parse(const char *fmt, va_list args, t_arg *l);
t_arg				*crt_lst(t_arg *l);
t_arg				*search_flags(t_arg *l, const char *fmt);
t_arg				*search_lenm(t_arg *l, const char *fmt);
t_arg				*search_prec(t_arg *l, const char *fmt,
					va_list args);
t_arg				*search_conv(t_arg *l, const char *fmt);
int					select_print(t_arg *l, va_list args);
int					select_print_c(t_arg *l, va_list args);
int					print_nbr(t_arg *l, va_list args);
int					ft_uintmlen_base(uintmax_t n, int base);
void				ft_putl(intmax_t n);
char				*ft_ctoa(char c);
char				*ft_uintmtoa_base(uintmax_t n, int base, char *conv);
int					print_hex(t_arg *l, va_list args);
int					print_octal(t_arg *l, va_list args);
int					print_binary(t_arg *l, va_list args);
int					print_c(t_arg *l, va_list args);
int					print_s(t_arg *l, va_list args);
char				*print_prec(t_arg *l, char *arg);
int					print_unbr(t_arg *l, va_list args);
int					print_p(t_arg *l);
int					prec_p(t_arg *l, const char *fmt, va_list args);
int					prec_d(t_arg *l, const char *fmt, va_list args);
char				*choose_type(t_arg *l, va_list args);
char				*ft_imtoa(intmax_t n);
int					print_wchar(t_arg *l, va_list args);
int					mask_apply_1(unsigned int n, int size, t_arg *l);
int					mask_apply_2(unsigned int n, t_arg *l);
int					mask_apply_3(unsigned int n, t_arg *l);
int					w_size(wint_t value);
int					select_wchar(t_arg *l, wint_t value);
int					print_wc(t_arg *l, va_list args);
int					print_ws(t_arg *l, va_list args);
void				print_lenf(t_arg *l);
void				choose_prec(t_arg *l, char *arg);
void				apply_flags(t_arg *l, char *arg);
char				*is_neg(char *n, t_arg *l);
char				*choose_utype(t_arg *l, va_list args, int base);
void				lst_reset(t_arg *l);
int					ft_uintlen_base(unsigned int n, int base);
char				*ft_uinttoa(unsigned int n, int base, char *conv);
char				*ft_uctoa(unsigned char n, int base, char *conv);
void				apply_flags_s(t_arg *l, char *arg);
int					prec_wild(t_arg *l, const char *fmt, va_list args, int i);

#endif
