/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pidlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 18:42:13 by apieropa          #+#    #+#             */
/*   Updated: 2014/02/09 21:00:09 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/serveur.h"

t_pidlist	*pidlist_new(int pid)
{
	t_pidlist	*n_pidlist;

	if ((n_pidlist = (t_pidlist *)malloc(sizeof(t_pidlist))) == NULL)
		exit(0);
	n_pidlist->pid = pid;
	n_pidlist->prompt = NULL;
	n_pidlist->color = NULL;
	n_pidlist->str = NULL;
	n_pidlist->next = NULL;
	return (n_pidlist);
}

t_pidlist	*pidlist_get(t_pidlist **begin, int pid)
{
	t_pidlist	*cur_list;

	if (*begin == NULL)
	{
		*begin = pidlist_new(pid);
		return (*begin);
	}
	cur_list = *begin;
	while (cur_list->pid != pid && cur_list->next != NULL)
		cur_list = cur_list->next;
	if (cur_list->pid == pid)
		return (cur_list);
	cur_list->next = pidlist_new(pid);
	return (cur_list);
}
