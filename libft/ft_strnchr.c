/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:03:02 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/21 20:23:08 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_strnchr(const char *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0' && i < n)
		i++;
	if (s[i] == (char)c && s[i] != '\0' && i < n)
		return ((char *)&(s[i]));
	return (NULL);
}
