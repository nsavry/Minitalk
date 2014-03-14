/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:05:01 by apieropa          #+#    #+#             */
/*   Updated: 2014/01/29 18:01:52 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

void		ft_bzero(void *s, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
