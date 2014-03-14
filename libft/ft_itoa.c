/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 15:20:54 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:33:05 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_itoa(int n)
{
	int		sign;
	char	*buff;
	int		len;
	int		i;

	sign = (n < 0 ? 'n' : 'p');
	n = (n < 0 ? -n : n);
	len = ft_nbrlen(n);
	buff = (sign == 'n' ? ft_strnew(len + 1) : ft_strnew(len));
	if (buff == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buff[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	buff[i] = (sign == 'n' ? '-' : 0);
	ft_strrev(buff);
	return (buff);
}
