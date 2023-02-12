/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:06:20 by bel-kase          #+#    #+#             */
/*   Updated: 2023/02/12 13:31:21 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long nb)
{
	unsigned long int	n;
	int					offset;

	n = 0;
	offset = 0;
	if (nb < 0)
	{
		n -= nb;
		offset += ft_putchar('-');
	}
	else
		n = nb;
	if (n >= 10)
	{
		offset += ft_putnbr(n / 10);
		offset += ft_putnbr(n % 10);
	}
	else
		offset += ft_putchar(n + 48);
	return (offset);
}
