/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 19:05:09 by apieropa          #+#    #+#             */
/*   Updated: 2014/01/05 17:18:45 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_strtrim(const char *s)
{
	int		i;
	int		i_start;
	int		i_end;
	char	*s2;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	i_start = i;
	i = ft_strlen((char *)s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
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
