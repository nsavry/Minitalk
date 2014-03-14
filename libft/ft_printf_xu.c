/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 14:03:34 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:41:27 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_printf_xu(void *n)
{
	char		*buff;
	long int	len;
	long int	i;
	long int	nb;
	char		base[16] = "0123456789ABCDEF";

	nb = (int)(long int)n;
	len = ft_nbrlen_base(nb, 16);
	if ((buff = ft_strnew(len)) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buff[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	ft_strrev(buff);
	return (buff);
}
