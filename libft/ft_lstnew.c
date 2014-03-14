/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:37:01 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:33:45 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list		*n_list;

	if ((n_list = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		n_list->content = NULL;
		n_list->content_size = 0;
	}
	else
	{
		if ((n_list->content = ft_memalloc(content_size)) == NULL)
			return (NULL);
		ft_memcpy(n_list->content, content, content_size);
		n_list->content_size = content_size;
	}
	n_list->next = NULL;
	return (n_list);
}
