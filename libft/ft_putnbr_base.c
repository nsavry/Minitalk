/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 15:12:15 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:42:56 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

void		ft_putnbr_base(int nb, char *base)
{
	char	c;
	int		len_base;

	len_base = ft_strlen(base);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb / len_base > 0)
	{
		ft_putnbr_base(nb / len_base, base);
		ft_putnbr_base(nb % len_base, base);
	}
	else
	{
		c = base[nb];
		write(1, &c, 1);
	}
}
