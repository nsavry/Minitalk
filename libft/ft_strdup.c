/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 08:18:40 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:45:01 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_strdup(const char *s)
{
	char	*s2;

	if ((s2 = ft_strnew(ft_strlen((char *)s))) == NULL)
		return (NULL);
	ft_strcpy(s2, s);
	return (s2);
}
