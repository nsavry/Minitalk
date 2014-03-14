/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 17:35:29 by apieropa          #+#    #+#             */
/*   Updated: 2014/02/09 19:10:22 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/serveur.h"

t_str		*tstr_new(char c)
{
	t_str	*n_str;

	if ((n_str = (t_str *)malloc(sizeof(t_str))) == NULL)
		exit(0);
	n_str->c = c;
	n_str->next = NULL;
	return (n_str);
}

void		tstr_add(t_str **begin, char c)
{
	t_str	*cur_str;

	if (*begin == NULL)
	{
		*begin = tstr_new(c);
		return ;
	}
	cur_str = *begin;
	while (cur_str->next != NULL)
		cur_str = cur_str->next;
	cur_str->next = tstr_new(c);
}

int			tstr_nbr(t_str *begin)
{
	t_str	*cur_str;
	int		i;

	if (begin == NULL)
		return (0);
	cur_str = begin;
	i = 0;
	while (cur_str != NULL)
	{
		cur_str = cur_str->next;
		i++;
	}
	return (i);
}

char		*tstr_convert(t_str *str)
{
	t_str	*cur_str;
	char	*n_str;
	int		i;

	if ((n_str = (char *)malloc(sizeof(char) * (tstr_nbr(str) + 1))) == NULL)
		exit(0);
	cur_str = str;
	if (cur_str == NULL)
		return (n_str);
	i = 0;
	while (cur_str != NULL)
	{
		n_str[i] = cur_str->c;
		i++;
		cur_str = cur_str->next;
	}
	n_str[i] = '\0';
	return (n_str);
}

void		tstr_del(t_str *str)
{
	t_str	*cur_str;
	t_str	*next_str;

	if (str == NULL)
		return ;
	cur_str = str;
	while (cur_str != NULL)
	{
		next_str = cur_str->next;
		free(cur_str);
		cur_str = next_str;
	}
}
