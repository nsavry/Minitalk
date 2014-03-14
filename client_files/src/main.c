/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 23:54:50 by apieropa          #+#    #+#             */
/*   Updated: 2014/02/09 21:19:08 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/client.h"

static void	wait_sentence(int pid);
static void	send_char(char *str, int pid);
static void	send_param(int pid, char *msg, char *name, char *color);

int			main(int ac, char **av)
{
	int					pid;
	struct sigaction	act;

	act.sa_sigaction = &handle;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGKILL, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
	sigaction(SIGINT, &act, NULL);
	if (ac < 3 || ac > 5)
	{
		ft_printf("Client: Arguments Error\n");
		ft_printf("Usage: client pid message [name [color]]\n");
		exit(0);
	}
	if (ac == 5)
		send_param(pid = ft_atoi(av[1]), av[2], av[3], av[4]);
	else if (ac == 4)
		send_param(pid = ft_atoi(av[1]), av[2], av[3], "default");
	else if (ac == 3)
		send_param(pid = ft_atoi(av[1]), av[2], av[0], "default");
	handle(-pid, NULL, NULL);
	wait_sentence(pid);
	return (0);
}

static void	wait_sentence(int pid)
{
	char	*line;
	int		ret;

	while (42)
	{
		if ((ret = get_next_line(0, &line)) == -1)
			exit(0);
		if (ft_strequ("/exit", line) || ret == 0)
		{
			send_char("--Is Disconnecting--", pid);
			free(line);
			exit(0);
		}
		send_char(line, pid);
		free(line);
	}
}

static void	send_param(int pid, char *msg, char *name, char *color)
{
	send_char(name, pid);
	send_char(color, pid);
	send_char(msg, pid);
}

void		handle(int i, siginfo_t *info, void *uap)
{
	static int	pid = 0;

	(void)i;
	(void)info;
	(void)uap;
	if (i < 0)
		pid = -i;
	if (i == SIGKILL || i == SIGQUIT || i == SIGINT)
	{
		send_char("--Is Disconnecting--", pid);
		ft_putchar('\n');
		exit(0);
	}
}

static void	send_char(char *str, int pid)
{
	long unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		code_char(str[i], pid);
		i++;
	}
	code_char(str[i], pid);
}
