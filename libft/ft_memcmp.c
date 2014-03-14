/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:38:07 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:35:08 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*s1_cp;
	unsigned char		*s2_cp;

	s1_cp = (unsigned char *)s1;
	s2_cp = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_cp[i] != s2_cp[i])
			return (s1_cp[i] - s2_cp[i]);
		i++;
	}
	return (0);
}
