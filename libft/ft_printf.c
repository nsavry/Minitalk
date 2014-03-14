/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 00:44:19 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/23 20:47:46 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>
#include	<ft_printf.h>

static char	ft_printf_parsing(char *format, va_list *ap, int *start, int *ret);
static char	*ft_printf_convert(va_list *ap, char *flag);
static void	ft_printf_tab_fl(char ***tab_fl);
static void	ft_printf_tab_fo(char *(***tab_fo)(void *));

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			start;
	int			ret;

	start = 0;
	ret = 0;
	va_start(ap, format);
	while (ft_strchr(format + start, '%') != NULL)
	{
		if ((ft_printf_parsing((char *)format, &ap, &start, &ret)) == 'e')
			return (-1);
	}
	ft_putstr(format + start);
	ret += ft_strlen(format) - start;
	va_end(ap);
	return (ret);
}

static char	ft_printf_parsing(char *format, va_list *ap, int *start, int *ret)
{
	char	*str;
	int		len;

	len = ft_strchr(format + *start, '%') - (format + *start);
	if ((str = ft_strsub(format, *start, len)) == NULL)
		return ('e');
	ft_putstr(str);
	*ret += ft_strlen(str);
	free(str);
	if ((str = ft_printf_convert(ap, format + *start + len)) == NULL)
		return ('e');
	ft_putstr(str);
	*ret += ft_strlen(str);
	free(str);
	*start += len + 2;
	return ('o');
}

static char	*ft_printf_convert(va_list *ap, char *flag)
{
	char	**tab_fl;
	char	*(**tab_fo)(void *);
	int		i;
	char	*tmp;

	if ((tab_fl = (char **)malloc(sizeof(char *) * 11)) == NULL)
		return (NULL);
	if ((tab_fo = (char *(**)(void *))malloc(sizeof(*tab_fo) * 11)) == NULL)
		return (NULL);
	ft_printf_tab_fl(&tab_fl);
	ft_printf_tab_fo(&tab_fo);
	if (tab_fl == NULL)
		return (NULL);
	i = 0;
	while (i < 11 && ft_strncmp(flag, tab_fl[i], 2) != 0)
		i++;
	tmp = "a";
	tmp = (tab_fo[i])(va_arg(*ap, void *));
	free(tab_fl);
	free(tab_fo);
	return (tmp);
}

static void	ft_printf_tab_fl(char ***tab_fl)
{
	*(*tab_fl + 0) = "%b";
	*(*tab_fl + 1) = "%c";
	*(*tab_fl + 2) = "%d";
	*(*tab_fl + 3) = "%i";
	*(*tab_fl + 4) = "%%";
	*(*tab_fl + 5) = "%o";
	*(*tab_fl + 6) = "%p";
	*(*tab_fl + 7) = "%s";
	*(*tab_fl + 8) = "%u";
	*(*tab_fl + 9) = "%x";
	*(*tab_fl + 10) = "%X";
}

static void	ft_printf_tab_fo(char *(***tab_fo)(void *))
{
	*(*tab_fo + 0) = &ft_printf_b;
	*(*tab_fo + 1) = &ft_printf_c;
	*(*tab_fo + 2) = &ft_printf_i;
	*(*tab_fo + 3) = &ft_printf_i;
	*(*tab_fo + 4) = &ft_printf_m;
	*(*tab_fo + 5) = &ft_printf_o;
	*(*tab_fo + 6) = &ft_printf_p;
	*(*tab_fo + 7) = &ft_printf_s;
	*(*tab_fo + 8) = &ft_printf_u;
	*(*tab_fo + 9) = &ft_printf_x;
	*(*tab_fo + 10) = &ft_printf_xu;
}
