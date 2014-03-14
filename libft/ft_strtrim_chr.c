/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_chr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 19:10:31 by apieropa          #+#    #+#             */
/*   Updated: 2014/01/05 17:23:10 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_strtrim_chr(const char *s, char c)
{
	int		i;
	int		i_start;
	int		i_end;
	char	*s2;

	i = 0;
	while (s[i] == c)
		i++;
	i_start = i;
	i = ft_strlen((char *)s) - 1;
	while (s[i] == c)
		i--;
	i_end = i;
	if (i < 0)
	{
		if ((s2 = ft_strnew(0)) == NULL)
			return (NULL);
		return (s2);
	}
	if ((s2 = ft_strsub(s, i_start, i_end - i_start + 1)) == NULL)
		return (NULL);
	return (s2);
}
