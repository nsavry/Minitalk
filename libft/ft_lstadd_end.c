/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 15:14:16 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/11 12:50:06 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

void		ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list		*cur_list;

	cur_list = *alst;
	while (cur_list->next != NULL)
		cur_list = cur_list->next;
	cur_list->next = new;
}
