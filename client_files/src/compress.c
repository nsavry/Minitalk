/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 21:51:29 by apieropa          #+#    #+#             */
/*   Updated: 2014/02/09 19:05:28 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/client.h"

static void	send_special(int i, int pid);
static void	send_current(char c, int pid);

int			code_char(char c, int pid)
{
	const char	str_custom[] = "esaitnrulodcpm ";
	int			i;

	i = 0;
	while (i < 15)
	{
		if (c == str_custom[i])
		{
			send_special(i, pid);
			return (0);
		}
		i++;
	}
	send_current(c, pid);
	return (0);
}

static void	send_special(int i, int pid)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		if (((i >> j) & 1) != 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(25);
		j++;
	}
}

static void	send_current(char c, int pid)
{
	char	j;

	j = 0;
	kill(pid, SIGUSR2);
	usleep(25);
	kill(pid, SIGUSR2);
	usleep(25);
	kill(pid, SIGUSR2);
	usleep(25);
	kill(pid, SIGUSR2);
	usleep(25);
	while (j < 8)
	{
		if (((c >> j) & 1) != 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(25);
		j++;
	}
}
