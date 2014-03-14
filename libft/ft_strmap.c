/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 14:58:07 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:46:49 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	char	*s2;
	int		len;

	len = ft_strlen((char *)s);
	s2 = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		s2[i] = (*f)(s[i]);
		i++;
	}
	return (s2);
}
