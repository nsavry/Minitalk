/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 04:47:19 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:34:24 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

void		*ft_memalloc(size_t size)
{
	size_t		i;
	void		*str;

	if ((str = malloc(size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)str)[i] = '\0';
		i++;
	}
	return (str);
}
