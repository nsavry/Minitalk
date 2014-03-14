/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:34:16 by apieropa          #+#    #+#             */
/*   Updated: 2014/02/09 11:06:41 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LIBFT_H
# define	LIBFT_H

# include	<string.h>
# include	<unistd.h>
# include	<stdlib.h>

/*
** ver 0.140113
*/

/*
** Macros
*/
# define		CR_RED			"\033[0;31m"
# define		CR_GREEN		"\033[0;32m"
# define		CR_YELLOW		"\033[0;33m"
# define		CR_BLUE			"\033[0;34m"
# define		CR_PURPLE		"\033[0;35m"

# define		CR_LRED			"\033[1;31m"
# define		CR_LGREEN		"\033[1;32m"
# define		CR_LYELLOW		"\033[1;33m"
# define		CR_LBLUE		"\033[1;34m"
# define		CR_LPURPLE		"\033[1;35m"

# define		CR_DEF			"\033[0m"

/*
** Structs
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Functions
*/
int			ft_atoi(const char *str);

void		ft_bzero(void *s, size_t n);

char		*ft_ctoa(char c);

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);

char		*ft_itoa(int n);

void		ft_lstadd_end(t_list **alst, t_list *new);
void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list		*ft_lstelem(t_list *begin_list, size_t n);
t_list		*ft_lstnew(const void *content, size_t content_size);
void		ft_lstprint_str(t_list **list, char c);
int			ft_lstsize(t_list *alst);

void		*ft_memalloc(size_t size);
void		*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
void		ft_memdel(void  **ap);
void		*ft_memmove(void *s1, const void *s2, size_t n);
void		*ft_memset(void *b, int c, size_t len);

int			ft_nbrchr(const char *str, char c);
int			ft_nbrlen(long int nb);
int			ft_nbrlen_base(long int nb, int base);

long int	ft_power(int n, int power);

int			ft_printf(const char *format, ...);
char		*ft_printf_b(void *c);
char		*ft_printf_c(void *c);
char		*ft_printf_i(void *n);
char		*ft_printf_m(void *c);
char		*ft_printf_o(void *n);
char		*ft_printf_p(void *n);
char		*ft_printf_s(void *s);
char		*ft_printf_u(void *n);
char		*ft_printf_x(void *n);
char		*ft_printf_xu(void *n);

void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl(const char *s);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putnbr(int nb);
void		ft_putnbr_base(int nb, char *base);
void		ft_putnbr_fd(int nb, int fd);
void		ft_putstr(const char *str);
void		ft_putstr_debug(char *str, int n);
void		ft_putstr_fd(const char *str, int fd);

char		*ft_strcat(char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
void		ft_strclr(char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *s1, const char *s2);
char		*ft_strcut(const char *s, int cutstart, int cutend);
void		ft_strdel(char **as);
char		*ft_strdel_chr(char *str, char c);
char		*ft_strdup(const char *s);
int			ft_strequ(char const *s1, char const *s2);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(const char *s1, const char *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strmap(const char *s, char (*f)(char));
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char		*ft_strncat(char *s1, const char *s2, size_t n);
char		*ft_strnchr(const char *s, int c, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *s1, const char *s2, size_t n);
char		*ft_strndup(const char *s, size_t i);
int			ft_strnequ(const char *s1, const char *s2, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *s, int c);
void		ft_strrev(char *str);
char		**ft_strsplit(const char *s, char c);
char		**ft_strsplit_av(const char *s);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strsub(const char *s, size_t start, size_t len);
char		*ft_strtrim(const char *s);
char		*ft_strtrim_chr(const char *s, char c);

int			ft_tolower(int c);
int			ft_toupper(int c);

int			get_next_line(const int fd, char ** line);

#endif  /* !LIBFT_H */
