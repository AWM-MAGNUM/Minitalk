/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:05:48 by bel-kase          #+#    #+#             */
/*   Updated: 2023/02/11 15:05:57 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_walk(va_list ptr, char str)
{
	int			offset;
	int			i;

	i = 0;
	offset = 0;
	if (str == 'c')
		offset += ft_putchar(va_arg(ptr, int));
	else if (str == 'i' || str == 'd')
		offset += ft_putnbr(va_arg(ptr, int));
	else if (str == 's')
		offset += ft_putstr(va_arg(ptr, void *));
	else if (str == 'u')
		offset += ft_putnbr(va_arg(ptr, unsigned int));
	else if (str == 'p')
	{
		offset += ft_putstr("0x");
		ft_xoxo(va_arg(ptr, unsigned long int), "0123456789abcdef", &offset);
	}
	else if (str == 'x')
		ft_xoxo(va_arg(ptr, unsigned int), "0123456789abcdef", &offset);
	else if (str == 'X')
		ft_xoxo(va_arg(ptr, unsigned int), "0123456789ABCDEF", &offset);
	else
		offset += ft_putchar(str);
	return (offset);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			offset;
	va_list		ptr;

	i = 0;
	offset = 0;
	va_start(ptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			offset += ft_walk(ptr, str[i]);
		}
		else
			offset += ft_putchar(str[i]);
			i++;
	}
	va_end(ptr);
	return (offset);
}
