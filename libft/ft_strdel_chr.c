/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 18:21:00 by apieropa          #+#    #+#             */
/*   Updated: 2014/01/25 18:34:37 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_strdel_chr(char *str, char c)
{
	int		i;
	int		j;
	char	*nstr;

	nstr = ft_strnew(ft_strlen(str) - ft_nbrchr(str, c));
	i = j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			nstr[j] = str[i];
			j++;
		}
		i++;
	}
	return (nstr);
}
