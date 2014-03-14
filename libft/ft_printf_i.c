/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 16:23:54 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:39:38 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_printf_i(void *n)
{
	int			sign;
	char		*buff;
	long int	len;
	long int	i;
	long int	nb;

	nb = (long int)(int)(long int)n;
	sign = (nb < 0 ? 'n' : 'p');
	nb = (nb < 0 ? -nb : nb);
	len = ft_nbrlen(nb);
	buff = (sign == 'n' ? ft_strnew(len + 1) : ft_strnew(len));
	if (buff == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buff[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	buff[i] = (sign == 'n' ? '-' : 0);
	ft_strrev(buff);
	return (buff);
}
