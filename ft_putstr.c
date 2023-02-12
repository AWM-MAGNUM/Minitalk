/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:12:12 by bel-kase          #+#    #+#             */
/*   Updated: 2023/02/11 15:14:32 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int		offset;
	size_t	i;

	i = 0;
	offset = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		offset += ft_putchar(str[i]);
		i++;
	}
	return (offset);
}
