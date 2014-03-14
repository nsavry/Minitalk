/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uncompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 21:58:25 by apieropa          #+#    #+#             */
/*   Updated: 2014/02/09 16:00:17 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/serveur.h"

static int	built_byte_one(char *c, char *c1);
static int	built_byte_two(t_pidlist *list, char *c, char *c1);

void		decode_char(t_pidlist *list, char *c)
{
	const char		str_custom[] = "esaitnrulodcpm ";
	static int		test = 0;
	static char		c1;

	if (test == 0)
	{
		if (*c < 15)
			tstr_add(&(list->str), *(str_custom + *c));
		else
			test = 1;
	}
	else if (test == 1)
		test = built_byte_one(c, &c1);
	else
		test = *c = built_byte_two(list, c, &c1);
}

static int	built_byte_one(char *c, char *c1)
{
	*c1 = *c;
	return (2);
}

static int	built_byte_two(t_pidlist *list, char *c, char *c1)
{
	*c = *c1 + (*c << 4);
	if (*c != 0)
		tstr_add(&(list->str), *c);
	else
		print_str(list);
	return (0);
}
