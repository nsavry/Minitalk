/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 19:46:09 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:37:16 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

int			ft_nbrlen_base(long int nb, int base)
{
	int		len;
	char	sign;

	len = 0;
	sign = (nb < 0 ? 'n' : 'p');
	nb = (nb < 0 ? -nb : nb);
	while (nb / ft_power(base, len) != 0)
		(len)++;
	len = (nb == 0 ? 1 : len);
	if (sign == 'p')
		return (len);
	return (len + 1);
}
