/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 16:38:40 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:48:33 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if ((char)c == '\0')
		return ((char *)&(s[i]));
	while (i != 0 && s[i] != (char)c)
		i--;
	if (s[i] == (char)c)
		return ((char *)&(s[i]));
	return (NULL);
}
