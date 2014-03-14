/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 17:35:04 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:39:30 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_printf_c(void *c)
{
	int		nb;
	char	*buff;

	nb = (int)(long int)c;
	if ((buff = ft_strnew(1)) == NULL)
		(buff = NULL);
	else
		buff[0] = (unsigned char)nb;
	return (buff);
}
