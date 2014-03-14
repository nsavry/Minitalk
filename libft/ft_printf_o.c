/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 19:07:17 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:39:56 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_printf_o(void *n)
{
	char		*buff;
	long int	len;
	long int	i;
	long int	nb;

	nb = (int)(long int)n;
	len = ft_nbrlen_base(nb, 8);
	if ((buff = ft_strnew(len)) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buff[i] = nb % 8 + '0';
		nb = nb / 8;
		i++;
	}
	ft_strrev(buff);
	return (buff);
}
