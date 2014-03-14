/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 04:34:03 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:43:17 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

void		ft_putnbr_fd(int nb, int fd)
{
	char	c;

	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb / 10 > 0)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		c = nb + '0';
		write(fd, &c, 1);
	}
}
