/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_av.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:47:15 by apieropa          #+#    #+#             */
/*   Updated: 2014/01/25 19:05:22 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>

static int		ft_strsplit_av_cnt(char *s);
static char		*ft_strsplit_av_alloc_s(int i_a, char *s);
static char		*ft_strsplit_av_fill_str(char *s, int i_start, int i_end);

char			**ft_strsplit_av(const char *s)
{
	int		len;
	char	**tab;
	int		slot;

	len = ft_strsplit_av_cnt((char *)s);
	if ((tab = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	slot = 0;
	while (slot < len)
	{
		tab[slot] = ft_strsplit_av_alloc_s(slot, (char *)s);
		slot++;
	}
	tab[slot] = NULL;
	return (tab);
}

static int		ft_strsplit_av_cnt(char *s)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t')
		{
			sum++;
			while (s[i] != '\0' && (s[i] != ' ' && s[i] != '\t'))
				i++;
		}
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
	}
	return (sum);
}

static char		*ft_strsplit_av_alloc_s(int slot, char *s)
{
	int		i_start;
	int		i_end;
	int		i_slot;
	char	*n_s;

	i_start = 0;
	while (s[i_start] == ' ' || s[i_start] == '\t')
		i_start++;
	i_slot = 0;
	while (i_slot < slot)
	{
		while (s[i_start] != '\0' && (s[i_start] != ' ' && s[i_start] != '\t'))
			i_start++;
		while (s[i_start] != '\0' && (s[i_start] == ' ' || s[i_start] == '\t'))
			i_start++;
		i_slot++;
	}
	i_end = i_start;
	while (s[i_end] != '\0' && (s[i_end] != ' ' && s[i_end] != '\t'))
		i_end++;
	if ((n_s = ft_strsplit_av_fill_str(s, i_start, i_end)) == NULL)
		return (NULL);
	return (n_s);
}

static char		*ft_strsplit_av_fill_str(char *s, int i_start, int i_end)
{
	char	*n_s;
	char	*tmp1;
	char	*tmp2;

	if ((tmp1 = ft_strsub(s, i_start, i_end - i_start)) == NULL)
		return (NULL);
	if ((tmp2 = ft_strdel_chr(tmp1, '"')) == NULL)
		return (NULL);
	free(tmp1);
	if ((n_s = ft_strdel_chr(tmp2, '\'')) == NULL)
		return (NULL);
	free(tmp2);
	return (n_s);
}
