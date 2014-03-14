/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 11:15:01 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/29 19:09:03 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

void		ft_putstr_debug(char *str, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (str[i] == '\0')
			ft_putstr("\\0");
		else if (str[i] == '\n')
			ft_putstr("\\n");
		else if (str[i] == '\t')
			ft_putstr("\\t");
		else if (str[i] == ' ')
			ft_putstr("'sp'");
		else
			ft_putchar(str[i]);
		ft_putchar(' ');
		i++;
	}
}
