/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 01:48:11 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/09 02:39:41 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define ANSI_COLOR_RED		"\x1B[31m"
#define ANSI_COLOR_RESET	"\x1b[0m"
#define ANSI_COLOR_GREEN	"\x1b[32m"
#define ANSI_COLOR_MAGENTA	"\x1b[33m"

void	ft_putstr_c(char *s)
{
	ft_putstr(ANSI_COLOR_RED);
	ft_putstr(s);
	ft_putstr(ANSI_COLOR_RESET);
}

void	ft_putstr_m(char *s)
{
	ft_putstr(ANSI_COLOR_MAGENTA);
	ft_putstr(s);
	ft_putstr(ANSI_COLOR_RESET);
}

void	ft_putchar_g(char c)
{
	ft_putstr(ANSI_COLOR_GREEN);
	ft_putchar(c);
	ft_putstr(ANSI_COLOR_RESET);
}
