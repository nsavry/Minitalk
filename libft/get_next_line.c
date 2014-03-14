/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 10:37:26 by apieropa          #+#    #+#             */
/*   Updated: 2014/01/13 02:34:54 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<libft.h>
#include	<get_next_line.h>

/*
** get_next_line: main function.
**
** _rx(redux): -Parses and store read(2) buffers. Returns 'r' to self-relaunch,
**                                                        'l' to self-relaunch,
**                                                        'L' to end of line,
**                                                        'f' to end of file,
**                                                        'e' to error
**
** _rea(re-alloc): -Reallocates enough space for *line. Returns 'e' on error.
**
** _select_fd: -Returns the structure corresponding to the fd.
**              If she does not exits, it adds it to the list.
**
** _free_fd: -Free the struct of a fd when done reading the file.
*/

static char		get_next_line_rx(t_gnl *cur_fd, char **line, int *i, char lr);
static char		get_next_line_rea(char **line, int n_size);
static t_gnl	*get_next_line_select_fd(t_gnl **begin, int fd);
static void		get_next_line_free_fd(t_gnl **begin, int fd);

int				get_next_line(const int fd, char **line)
{
	int				i;
	int				ret_rx;
	static t_gnl	*begin = NULL;
	t_gnl			*cur_fd;

	i = 0;
	if ((cur_fd = get_next_line_select_fd(&begin, fd)) == NULL)
		return (-1);
	ret_rx = 'r';
	while (ret_rx == 'r' || ret_rx == 'l')
	{
		if (i % BUFF_SIZE == 0 && ret_rx != 'l')
		{
			if (get_next_line_rea(line, i + BUFF_SIZE + 1) == 'e')
				return (-1);
		}
		if ((ret_rx = get_next_line_rx(cur_fd, line, &i, ret_rx)) == 'e')
			return (-1);
	}
	if (ret_rx == 'L')
		return (1);
	get_next_line_free_fd(&begin, fd);
	return (0);
}

/*
** Read(2) buffer parsing
*/

static char		get_next_line_rx(t_gnl *cur_fd, char **line, int *i, char lr)
{
	int				ret;

	if (cur_fd->end - cur_fd->start == 0)
	{
		if ((ret = read(cur_fd->fd, cur_fd->buff, BUFF_SIZE)) == -1)
			return ('e');
		if (ret == 0)
			return ('f');
		cur_fd->start = 0;
		cur_fd->end = ret;
		if (lr == 'l')
			return ('L');
	}
	if (cur_fd->buff[cur_fd->start] != '\n')
	{
		(*line)[(*i)++] = (cur_fd->buff)[cur_fd->start];
		(*line)[*i] = '\0';
		(cur_fd->start)++;
		return ('r');
	}
	(*line)[*i] = '\0';
	(cur_fd->start)++;
	if (cur_fd->end - cur_fd->start != 0 || cur_fd->fd == 0)
		return ('L');
	return ('l');
}

/*
** Realloc of **line
*/

static char		get_next_line_rea(char **line, int n_size)
{
	char	*n_line;

	if (n_size == BUFF_SIZE + 1)
	{
		if (((*line) = ((char *)malloc(sizeof(char) * n_size))) == NULL)
			return ('e');
		return ('o');
	}
	if ((n_line = ((char *)malloc(sizeof(char) * n_size))) == NULL)
		return ('e');
	ft_memmove(n_line, (*line), n_size - BUFF_SIZE + 1);
	free(*line);
	*line = n_line;
	return ('o');
}

/*
** Lists-relative functions
*/

static t_gnl	*get_next_line_select_fd(t_gnl **begin, int fd)
{
	t_gnl		*cur_list;
	char		esc;

	cur_list = *begin;
	esc = 'n';
	while (cur_list != NULL && esc != 'y')
	{
		esc = (cur_list->fd == fd ? 'y' : 'n');
		if (cur_list->fd != fd)
			cur_list = cur_list->next;
	}
	if (cur_list == NULL)
	{
		if ((cur_list = (t_gnl *)malloc(sizeof(t_gnl))) == NULL)
			return (NULL);
		if ((cur_list->buff = ft_strnew(BUFF_SIZE - 1)) == NULL)
			return (NULL);
		cur_list->fd = fd;
		cur_list->start = 0;
		cur_list->end = 0;
		cur_list->next = *begin;
		*begin = cur_list;
	}
	return (cur_list);
}

static void		get_next_line_free_fd(t_gnl **begin, int fd)
{
	t_gnl	*cur_list;
	t_gnl	*to_free_list;

	cur_list = *begin;
	if ((*begin)->next == NULL)
	{
		free((*begin)->buff);
		free(*begin);
		*begin = NULL;
		return ;
	}
	if (cur_list-> fd == fd)
	{
		to_free_list = cur_list;
		*begin = cur_list->next;
	}
	else
	{
		while (cur_list->next->fd != fd)
			cur_list = cur_list->next;
		to_free_list = cur_list->next;
		cur_list->next = cur_list->next->next;
	}
	free(to_free_list->buff);
	free(to_free_list);
}
