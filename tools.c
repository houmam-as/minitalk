/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:19:28 by hait-sal          #+#    #+#             */
/*   Updated: 2023/05/08 17:33:48 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	nbr_l(int n)
{
	long	num;
	int		i;

	num = n;
	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		i++;
	while (num)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		nl;
	char	*p;

	nb = n;
	nl = nbr_l(nb);
	p = malloc (nl * sizeof(char) + 1);
	if (!p)
		return (NULL);
	if (n == 0)
		p[0] = 48;
	else if (nb < 0)
	{
		p[0] = 45;
		nb *= -1;
	}
	while (nb)
	{
		p[nl - 1] = nb % 10 + 48;
		nb /= 10;
		nl--;
	}
	p[nbr_l(n)] = 0;
	return (p);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	ft_atoi(const char *str)
{
	int	s;
	int	r;

	s = 1;
	r = 0;
	while ((*str < 14 && *str > 8) || *str == 32)
			str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s = s * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - 48);
		str++;
	}
	return (r * s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}
