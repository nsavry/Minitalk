/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 15:49:22 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/21 15:57:00 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

int			ft_lstsize(t_list *alst)
{
	t_list		*cur_list;
	size_t		size;

	size = 0;
	cur_list = alst;
	while (cur_list != NULL)
	{
		cur_list = cur_list->next;
		size++;
	}
	return (size);
}
