/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 23:54:50 by apieropa          #+#    #+#             */
/*   Updated: 2014/02/09 21:15:51 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/serveur.h"

int			main(void)
{
	struct sigaction	act;

	ft_putendl("Server started.");
	ft_printf("Server PID: %d\n", getpid());
	act.sa_sigaction = &handle;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (42)
	{
	}
	return (0);
}

void		handle(int i, siginfo_t *info, void *uap)
{
	static t_pidlist	*list = NULL;
	t_pidlist			*cur_list;

	(void)uap;
	cur_list = pidlist_get(&list, info->si_pid);
	print_char(i % 30, cur_list);
}

void		print_char(t_bool sig, t_pidlist *list)
{
	static char		i = 0;
	static char		c = 0;

	if (sig == 1)
		c |= 0x1 << i;
	i++;
	if (i == 4)
	{
		decode_char(list, &c);
		i = c = 0;
	}
}
