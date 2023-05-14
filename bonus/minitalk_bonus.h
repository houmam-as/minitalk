/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:21:43 by hait-sal          #+#    #+#             */
/*   Updated: 2023/05/08 17:32:49 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# define SIG0 SIGUSR1
# define SIG1 SIGUSR2

typedef struct s_server
{
	char	*msg;
	int		len_recieved;
	int		len;
	int		c;
	int		i;
	int		index;
	pid_t	pid;
}	t_server;

//////////////////// minitalk functions ////////////////////

void	ft_putstr(char *str);
void	send_len_bit(int c, pid_t target_pid);
void	send_bit(char c, pid_t target_pid);
void	client_sig_handler(int sig);
void	init(void);
void	receive_len(int sig);
void	receive_msg(int sig);
void	sig_handler(int sig, siginfo_t *info, void *param);

//////////////////// libft functions ////////////////////

int		nbr_l(int n);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

#endif