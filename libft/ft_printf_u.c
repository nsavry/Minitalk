/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 19:09:50 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:40:53 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_printf_u(void *n)
{
	char		*buff;
	long int	len;
	long int	i;
	long int	nb;

	nb = (int)(long int)n;
	len = ft_nbrlen(nb);
	if ((buff = ft_strnew(len)) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buff[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	ft_strrev(buff);
	return (buff);
}
