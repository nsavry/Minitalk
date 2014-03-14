/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 18:51:58 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 23:48:43 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

void		ft_strrev(char *str)
{
	int		i;
	int		len;
	char	c;

	len = ft_strlen(str) - 1;
	i = 0;
	while (i <= len / 2)
	{
		c = str[i];
		str[i] = str[len - i];
		str[len - i] = c;
		i++;
	}
}
