/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:26:16 by hait-sal          #+#    #+#             */
/*   Updated: 2023/05/12 12:44:36 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_len_bit(int c, pid_t target_pid)
{
	int	i;
	int	bit;

	i = 31;
	while (i >= 0)
	{
		bit = c & (1 << i);
		if (bit == 0)
			kill(target_pid, SIG0);
		else
			kill(target_pid, SIG1);
		usleep(200);
		i--;
	}
}

void	send_bit(char c, pid_t target_pid)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = c & (1 << i);
		if (bit == 0)
			kill(target_pid, SIG0);
		else
			kill(target_pid, SIG1);
		usleep(200);
		i--;
	}
}

int	main(int ac, char *av[])
{
	int		i;
	int		len;
	pid_t	target_pid;

	if (ac != 3)
		exit (1);
	if (av[2][0] == '\0' || ft_atoi(av[1]) < 1)
		exit (0);
	i = 0;
	target_pid = ft_atoi(av[1]);
	len = ft_strlen(av[2]);
	send_len_bit(len, target_pid);
	while (av[2][i])
	{
		send_bit(av[2][i], target_pid);
		i++;
	}
	send_bit('\0', target_pid);
	return (0);
}
