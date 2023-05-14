/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:26:16 by hait-sal          #+#    #+#             */
/*   Updated: 2023/05/12 12:55:36 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	client_sig_handler(int sig)
{
	if (sig == SIG0)
		ft_putstr("MSG RECIEVED !\n");
	exit(0);
}

int	main(int ac, char *av[])
{
	int					i;
	int					len;
	struct sigaction	sa;
	pid_t				target_pid;

	if (ac != 3)
		exit (1);
	if (av[2][0] == '\0' || ft_atoi(av[1]) < 1)
		exit (0);
	i = -1;
	sa.sa_handler = client_sig_handler;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIG0, &sa, NULL) == -1)
	{
		ft_putstr("sigaction : error\n");
		return (1);
	}
	target_pid = ft_atoi(av[1]);
	len = ft_strlen(av[2]);
	send_len_bit(len, target_pid);
	while (av[2][++i])
		send_bit(av[2][i], target_pid);
	send_bit('\0', target_pid);
	pause();
	return (0);
}
