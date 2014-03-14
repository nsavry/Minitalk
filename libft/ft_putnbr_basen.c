/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_basen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 23:59:35 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:43:06 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

void		ft_putnbr_basen(int nb, int base)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb / base > 0)
	{
		ft_putnbr_basen(nb / base, base);
		ft_putnbr_basen(nb % base, base);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}
