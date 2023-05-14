/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:26:11 by hait-sal          #+#    #+#             */
/*   Updated: 2023/05/12 13:00:59 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server	g_data;

void	init(void)
{
	g_data.msg = NULL;
	g_data.len_recieved = 0;
	g_data.len = 0;
	g_data.c = 0;
	g_data.i = 0;
	g_data.index = 0;
}

void	receive_len(int sig)
{
	g_data.i++;
	g_data.len = g_data.len << 1;
	if (sig == SIG1)
		g_data.len = g_data.len | 1;
	if (g_data.i == 32)
	{
		g_data.msg = (char *)malloc((g_data.len + 1) * sizeof(char));
		g_data.i = 0;
		g_data.len_recieved = 1;
	}
}

void	receive_msg(int sig)
{
	g_data.i++;
	g_data.c = g_data.c << 1;
	if (sig == SIG1)
		g_data.c = g_data.c | 1;
	if (g_data.i == 8)
	{
		g_data.msg[g_data.index] = g_data.c;
		if (g_data.c != 0)
			g_data.index++;
		else
		{
			ft_putstr(g_data.msg);
			free(g_data.msg);
			init();
		}
		g_data.c = 0;
		g_data.i = 0;
	}
}

void	sig_handler(int sig, siginfo_t *info, void *param)
{
	(void)*param;
	if (g_data.pid != info->si_pid)
	{
		g_data.pid = info->si_pid;
		free(g_data.msg);
		init();
	}
	g_data.pid = info->si_pid;
	if (!g_data.len_recieved)
		receive_len(sig);
	else
		receive_msg(sig);
}

int	main(void)
{
	struct sigaction	sa;
	char				*pid;

	pid = ft_itoa(getpid());
	ft_putstr("PID : ");
	ft_putstr(pid);
	ft_putstr("\n");
	free(pid);
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIG0, &sa, NULL) == -1)
	{
		ft_putstr("sigaction : error\n");
		return (1);
	}
	if (sigaction(SIG1, &sa, NULL) == -1)
	{
		ft_putstr("sigaction : error\n");
		return (1);
	}
	init();
	while (1)
		pause();
	return (0);
}
