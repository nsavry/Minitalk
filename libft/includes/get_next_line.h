/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 10:37:47 by apieropa          #+#    #+#             */
/*   Updated: 2014/01/05 19:42:48 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

# include	<sys/types.h>
# include	<sys/uio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<libft.h>

# define	BUFF_SIZE	256

typedef struct		s_gnl
{
	int				fd;
	char			*buff;
	int				start;
	int				end;
	struct s_gnl	*next;
}					t_gnl;

int			get_next_line(const int fd, char ** line);

#endif  /*!GET_NEXT_LINE_H*/
