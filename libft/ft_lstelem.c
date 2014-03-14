/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstelem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 16:29:53 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/11 12:51:30 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

t_list		*ft_lstelem(t_list *begin_list, size_t n)
{
	size_t		i;
	t_list		*cur_list;

	i = 0;
	cur_list = begin_list;
	while (i < n && cur_list != NULL)
	{
		cur_list = cur_list->next;
		i++;
	}
	return (cur_list);
}
