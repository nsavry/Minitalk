/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:22:48 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:33:53 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

void		ft_lstprint_str(t_list **list, char c)
{
	t_list		*cur_list;

	cur_list = *list;
	while (cur_list != NULL)
	{
		if (cur_list->content != NULL)
			ft_putstr(cur_list->content);
		ft_putchar(c);
		cur_list = cur_list->next;
	}
}
