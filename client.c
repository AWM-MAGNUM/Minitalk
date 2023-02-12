/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:59:06 by bel-kase          #+#    #+#             */
/*   Updated: 2023/02/12 21:42:59 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(char	*str)
{
	int	i;
	int	res;
	int	signe;

	i = 0;
	res = 0;
	signe = 1;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res += str[i] - 48;
		i++;
	}
	return (res * signe);
}

void	ft_send_signal_to_process(int pid, unsigned char *tweet)
{
	int	i;

	i = 0;
	while (tweet[i])
	{
		if (tweet[i] == '0')
			kill (pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep (400);
		i++;
	}
	free (tweet);
}

unsigned char	*ascii_to_binary(unsigned char tweet)
{
	int				i;
	unsigned char	*res_data;

	i = 7;
	res_data = malloc(9);
	while (i >= 0)
	{
		res_data[i] = (tweet % 2) + 48;
		tweet = tweet / 2;
		i--;
	}
	res_data[8] = '\0';
	return (res_data);
}

int	main(int argc, char **argv)
{
	int				pid;
	int				i;
	unsigned char	*tweet;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid == -1 || pid == 0)
			return (1);
		while (argv[2][i])
		{
			tweet = (unsigned char *)ascii_to_binary(argv[2][i]);
			ft_send_signal_to_process(pid, tweet);
			i++;
		}
	}
	else
		write(1, "⛔Please ☹ enter ☹ enough ☹ arguments⛔", 47);
	return (0);
}
