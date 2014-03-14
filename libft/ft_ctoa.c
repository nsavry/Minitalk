/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:53:01 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/22 20:44:51 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

char		*ft_ctoa(char c)
{
	char	*buff;

	if ((buff = ft_strnew(1)) == NULL)
		(buff = NULL);
	else
		buff[0] = c;
	return (buff);
}
