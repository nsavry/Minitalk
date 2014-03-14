/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 04:22:07 by apieropa          #+#    #+#             */
/*   Updated: 2014/01/23 04:42:44 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_strcut(const char *s, int cutstart, int cutend)
{
	int		len;
	char	*str;

	len = ft_strlen(s) + cutend - cutstart;
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	ft_strncpy(str, s, cutstart);
	ft_strcpy(str + cutstart, s + cutend);
	return (str);
}
