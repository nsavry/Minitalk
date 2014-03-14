/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 23:56:01 by apieropa          #+#    #+#             */
/*   Updated: 2014/02/09 21:15:52 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SERVEUR_H
# define	SERVEUR_H

/*
** <Libs system>
*/
# include	<signal.h>
# include	<unistd.h>

/*
** "Libs user"
*/
# include	"../../libft/includes/libft.h"

/*
** MACROS
*/
# define	C_BLACK		"\033[0;30m"
# define	C_LBLACK	"\033[1;30m"
# define	C_RED		"\033[0;31m"
# define	C_LRED		"\033[1;31m"
# define	C_GREEN		"\033[0;32m"
# define	C_LGREEN	"\033[1;32m"
# define	C_YELLOW	"\033[0;33m"
# define	C_LYELLOW	"\033[1;33m"
# define	C_BLUE		"\033[0;34m"
# define	C_LBLUE		"\033[1;34m"
# define	C_PURPLE	"\033[0;35m"
# define	C_LPURPLE	"\033[1;35m"
# define	C_CYAN		"\033[0;36m"
# define	C_LCYAN		"\033[1;36m"
# define	C_GREY		"\033[0;37m"
# define	C_LGREY		"\033[1;37m"
# define	C_DEFAULT	"\033[0m"

/*
** Typedefs;
*/
typedef char				t_bool;

typedef struct	s_pidlist	t_pidlist;
typedef struct	s_str		t_str;

/*
** Structures{};
*/
struct				s_pidlist
{
	int				pid;
	char			*prompt;
	char			*color;
	char			*msg;
	t_str			*str;
	t_pidlist		*next;
};

struct				s_str
{
	char			c;
	t_str			*next;
};

/*
** Contents: main
*/
int			main(void);

void		handle(int i, siginfo_t *info, void *uap);
void		print_char(t_bool sig, t_pidlist *list);

/*
** Contents: t_str
*/
t_str		*tstr_new(char c);
void		tstr_add(t_str **begin, char c);
int			tstr_nbr(t_str *begin);
char		*tstr_convert(t_str *str);
void		tstr_del(t_str *str);

/*
** Contents: t_pidlist
*/
t_pidlist	*pidlist_new(int pid);
t_pidlist	*pidlist_get(t_pidlist **list, int pid);

/*
** Contents: uncompress
*/
void		decode_char(t_pidlist *list, char *c);

/*
** Contents: print
*/
void		print_str(t_pidlist *list);

#endif		/* !SERVEUR_H */
