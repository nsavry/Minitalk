/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 04:33:06 by apieropa          #+#    #+#             */
/*   Updated: 2014/01/24 04:39:26 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_strndup(const char *s, size_t i)
{
	char	*s2;

	if ((s2 = ft_strnew(i)) == NULL)
		return (NULL);
	ft_strncpy(s2, s, i);
	return (s2);
}
