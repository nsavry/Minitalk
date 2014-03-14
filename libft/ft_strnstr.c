/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 16:50:01 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:48:17 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		is1;
	size_t		is2;

	is1 = 0;
	is2 = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	if (s1[0] == '\0')
		return (NULL);
	while (s1[is1] != '\0' && is1 < n)
	{
		while (s1[is1] == s2[is2] && s2[is2] != '\0' && is1 < n)
		{
			is1++;
			is2++;
		}
		if (s2[is2] == '\0')
			return ((char *)&(s1[is1 - is2]));
		else
			is1 = is1 - is2;
		is2 = 0;
		is1++;
	}
	return (NULL);
}
