/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:01:22 by bel-kase          #+#    #+#             */
/*   Updated: 2023/02/12 22:05:03 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

static int	g_i;

int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putnbr(long long nb);
void	ft_xoxo(unsigned long int nb, char *t, int *offset);
#endif