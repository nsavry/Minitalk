/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 10:51:19 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:33:20 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*cur_list;
	t_list		*next_list;

	cur_list = *alst;
	while (cur_list != NULL)
	{
		next_list = cur_list->next;
		ft_lstdelone(&cur_list, del);
		cur_list = next_list;
	}
	*alst = NULL;
}
