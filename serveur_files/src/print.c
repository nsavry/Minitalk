/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 15:36:12 by apieropa          #+#    #+#             */
/*   Updated: 2014/02/09 19:53:39 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/serveur.h"

static char	*format_prompt(char *prompt);
static char	*format_color(char *color);
static void	fill_acolor(char ***acolor);
static void	fill_acolor_name(char ***acolor_name);

void		print_str(t_pidlist *list)
{
	if (list->prompt == NULL)
	{
		list->prompt = format_prompt(tstr_convert(list->str));
		tstr_del(list->str);
		list->str = NULL;
		return ;
	}
	if (list->color == NULL)
	{
		list->color = format_color(tstr_convert(list->str));
		tstr_del(list->str);
		list->str = NULL;
		return ;
	}
	list->msg = tstr_convert(list->str);
	tstr_del(list->str);
	list->str = NULL;
	ft_putstr(list->color);
	ft_putstr(list->prompt);
	ft_putendl(list->msg);
	ft_putstr(C_DEFAULT);
	free(list->msg);
	list->msg = NULL;
}

static char	*format_prompt(char *prompt)
{
	char	*new_pr;
	char	*tmp_pr;

	if ((tmp_pr = ft_strjoin("<", prompt)) == NULL)
		exit(0);
	free(prompt);
	if ((new_pr = ft_strjoin(tmp_pr, "> ")) == NULL)
		exit(0);
	free(tmp_pr);
	return (new_pr);
}

static char	*format_color(char *color)
{
	int			i;
	static char	**acolor = NULL;
	static char	**acolor_name = NULL;

	if (acolor == NULL)
		fill_acolor(&acolor);
	if (acolor_name == NULL)
		fill_acolor_name(&acolor_name);
	i = 0;
	while (acolor_name[i] != NULL)
	{
		if (ft_strequ(color, acolor_name[i]) == 1)
			return (acolor[i]);
		i++;
	}
	return (acolor[i]);
}

static void	fill_acolor(char ***acolor)
{
	if ((*acolor = (char **)malloc(sizeof(char *) * 17)) == NULL)
		exit(0);
	*(*acolor + 0) = C_BLACK;
	*(*acolor + 1) = C_LBLACK;
	*(*acolor + 2) = C_RED;
	*(*acolor + 3) = C_LRED;
	*(*acolor + 4) = C_GREEN;
	*(*acolor + 5) = C_LGREEN;
	*(*acolor + 6) = C_YELLOW;
	*(*acolor + 7) = C_LYELLOW;
	*(*acolor + 8) = C_BLUE;
	*(*acolor + 9) = C_LBLUE;
	*(*acolor + 10) = C_PURPLE;
	*(*acolor + 11) = C_LPURPLE;
	*(*acolor + 12) = C_CYAN;
	*(*acolor + 13) = C_LCYAN;
	*(*acolor + 14) = C_GREY;
	*(*acolor + 15) = C_LGREY;
	*(*acolor + 16) = "";
}

static void	fill_acolor_name(char ***acolor_name)
{
	if ((*acolor_name = (char **)malloc(sizeof(char *) * 17)) == NULL)
		exit(0);
	*(*acolor_name + 0) = "black";
	*(*acolor_name + 1) = "lightblack";
	*(*acolor_name + 2) = "red";
	*(*acolor_name + 3) = "lightred";
	*(*acolor_name + 4) = "green";
	*(*acolor_name + 5) = "lightgreen";
	*(*acolor_name + 6) = "yellow";
	*(*acolor_name + 7) = "lightyellow";
	*(*acolor_name + 8) = "blue";
	*(*acolor_name + 9) = "lightblue";
	*(*acolor_name + 10) = "purple";
	*(*acolor_name + 11) = "lightpurple";
	*(*acolor_name + 12) = "cyan";
	*(*acolor_name + 13) = "lightcyan";
	*(*acolor_name + 14) = "grey";
	*(*acolor_name + 15) = "lightgrey";
	*(*acolor_name + 16) = NULL;
}
