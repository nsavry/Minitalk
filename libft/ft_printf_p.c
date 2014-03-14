/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 14:12:49 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/23 19:57:34 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_printf_p(void *n)
{
	char		*buff;
	long int	len;
	long int	i;
	long int	nb;
	char		base[16] = "0123456789abcdef";

	nb = (long int)n;
	len = ft_nbrlen_base(nb, 16);
	if ((buff = ft_strnew(len + 2)) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buff[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	buff[i] = 'x';
	buff[i + 1] = '0';
	ft_strrev(buff);
	return (buff);
}
