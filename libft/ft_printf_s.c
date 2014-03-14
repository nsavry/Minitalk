/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 17:46:23 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:40:41 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_printf_s(void *s)
{
	char	*s1;
	char	*s2;

	s1 = (char *)s;
	if (s == NULL)
	{
		if ((s2 = ft_strnew(6)) == NULL)
			return (NULL);
		ft_strcpy(s2, "(null)");
		return (s2);
	}
	if ((s2 = ft_strnew(ft_strlen(s1))) == NULL)
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}
