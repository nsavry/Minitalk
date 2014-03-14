/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 19:07:17 by apieropa          #+#    #+#             */
/*   Updated: 2014/02/09 18:52:53 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_printf_b(void *n)
{
	char		*buff;
	long int	len;
	long int	i;
	long int	nb;

	nb = (int)(long int)n;
	len = ft_nbrlen_base(nb, 2);
	if ((buff = ft_strnew(len)) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buff[i] = nb % 2 + '0';
		nb = nb / 2;
		i++;
	}
	ft_strrev(buff);
	return (buff);
}
