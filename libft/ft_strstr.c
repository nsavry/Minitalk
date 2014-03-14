/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:42:40 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:49:12 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_strstr(const char *s1, const char *s2)
{
	int		is1;
	int		is2;

	is1 = 0;
	is2 = 0;
	while (s1[is1] != '\0')
	{
		while (s1[is1] == s2[is2] && s2[is2] != '\0')
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
