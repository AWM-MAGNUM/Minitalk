/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:38:25 by bel-kase          #+#    #+#             */
/*   Updated: 2023/02/12 22:08:47 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	binary_to_ascii(char *tweet)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (i < 8)
	{
		c = c * 2 + (tweet[i] - 48);
		i++;
	}
	write (1, &c, 1);
}

void	sigint_handler(int signum)
{
	static char	tweet[9];

	if (signum == SIGUSR1)
		tweet[g_i] = '0';
	else
		tweet[g_i] = '1';
	g_i++;
	if (g_i == 8)
	{
		tweet[g_i] = '\0';
		binary_to_ascii(tweet);
		g_i = 0;
	}
}

int	main(void)
{
	int		pid;

	g_i = 0;
	pid = getpid ();
	ft_printf("Processus ID : %d\n", pid);
	signal (SIGUSR1, sigint_handler);
	signal (SIGUSR2, sigint_handler);
	while (1)
		pause();
}
