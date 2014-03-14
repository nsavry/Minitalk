/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 23:56:01 by apieropa          #+#    #+#             */
/*   Updated: 2014/02/09 20:16:51 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CLIENT_H
# define	CLIENT_H

/*
** <Libs system>
*/
#include	<signal.h>
#include	<unistd.h>

/*
** "Libs user"
*/
#include	"../../libft/includes/libft.h"

/*
** MACROS
*/

/*
** Typedefs;
*/

/*
** Structures{};
*/

/*
** Contents: main
*/
int			main(int ac, char **av);
void		handle(int i, siginfo_t *info, void *uap);

/*
** Contents: compress
*/
int			code_char(char c, int pid);

#endif		/* !CLIENT_H */
