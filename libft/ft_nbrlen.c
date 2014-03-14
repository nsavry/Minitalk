/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 11:39:36 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:36:49 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

int			ft_nbrlen(long int nb)
{
	int			len;
	char		sign;

	len = 0;
	sign = (nb < 0 ? 'n' : 'p');
	nb = (nb < 0 ? -nb : nb);
	while (nb / ft_power(10, len) != 0)
		(len)++;
	len = (nb == 0 ? 1 : len);
	if (sign == 'p')
		return (len);
	return (len + 1);
}
