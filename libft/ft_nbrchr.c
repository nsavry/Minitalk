/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 08:04:08 by apieropa          #+#    #+#             */
/*   Updated: 2014/01/24 08:11:56 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

int			ft_nbrchr(const char *str, char c)
{
	int		i;
	int		nb;

	i = nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			nb++;
		i++;
	}
	return (nb);
}
