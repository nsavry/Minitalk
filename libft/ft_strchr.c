/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:46:33 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:44:01 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_strchr(const char *s, int c)
{
	size_t		i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c && s[i] != '\0')
		return ((char *)&(s[i]));
	return (NULL);
}
