/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xoxo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:14:44 by bel-kase          #+#    #+#             */
/*   Updated: 2023/02/11 17:19:14 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_xoxo(unsigned long int nb, char *t, int *offset)
{
	if (nb >= 16)
		ft_xoxo ((nb / 16), t, offset);
	*offset += ft_putchar (t[nb % 16]);
}
