/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:19:23 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:32:44 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

int			ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i] != '\0')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	nbr = 0;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
