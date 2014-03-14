/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:29:11 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/29 18:57:02 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

static int		ft_strsplit_cnt(char *s, char c);
static char		*ft_strsplit_alloc_s(int i_a, char *s, char c);

char			**ft_strsplit(const char *s, char c)
{
	int		len;
	char	**tab;
	int		slot;

	len = ft_strsplit_cnt((char *)s, c);
	if ((tab = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	slot = 0;
	while (slot < len)
	{
		tab[slot] = ft_strsplit_alloc_s(slot, (char *)s, c);
		slot++;
	}
	tab[slot] = NULL;
	return (tab);
}

static int		ft_strsplit_cnt(char *s, char c)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			sum++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	return (sum);
}

static char		*ft_strsplit_alloc_s(int slot, char *s, char c)
{
	int		i_start;
	int		i_end;
	int		i_slot;
	char	*n_s;

	i_start = 0;
	while (s[i_start] == c)
		i_start++;
	i_slot = 0;
	while (i_slot < slot)
	{
		while (s[i_start] != '\0' && s[i_start] != c)
			i_start++;
		while (s[i_start] != '\0' && s[i_start] == c)
			i_start++;
		i_slot++;
	}
	i_end = i_start;
	while (s[i_end] != '\0' && s[i_end] != c)
		i_end++;
	if ((n_s = ft_strsub(s, i_start, i_end - i_start)) == NULL)
		return (NULL);
	return (n_s);
}
