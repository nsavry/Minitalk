/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 19:05:55 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/23 19:23:20 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_printf_m(void *c)
{
	char	*buff;

	(void)c;
	if ((buff = ft_strnew(1)) == NULL)
		(buff = NULL);
	else
		buff[0] = '%';
	return (buff);
}
