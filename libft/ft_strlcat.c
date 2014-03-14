/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:05:10 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:46:28 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i_dst;
	int		i_src;
	int		i_dst_start;

	i_dst = 0;
	while (dst[i_dst] != '\0' && i_dst < (int)size)
		i_dst++;
	i_dst_start = i_dst;
	i_src = 0;
	while (src[i_src] != '\0' && i_dst < (int)size - 1)
	{
		dst[i_dst] = src[i_src];
		i_src++;
		i_dst++;
	}
	if (i_dst > i_dst_start)
		dst[i_dst] = '\0';
	return (i_dst_start + ft_strlen((char *)src));
}
