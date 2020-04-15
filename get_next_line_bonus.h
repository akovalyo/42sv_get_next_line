/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:00:34 by akovalyo          #+#    #+#             */
/*   Updated: 2020/04/15 13:24:40 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	int				fd;
	struct s_list	*next;
}					t_list;

char				*rest_text(char *ptr_rest, char **ptr_endl);
int					new_line(const int fd, char **line, char *ptr_rest,
						char **ptr_endl);
t_list				*new_elem(const int fd);
int					get_next_line(const int fd, char **line);
char				*ft_strchr(const char *s, int c);
void				ft_bzero(void *s, int n);
char				*ft_strnew(int size);
int					ft_strlen(const char *s);
char				*ft_subjoin(char const *s, int len, char const *s2,
						int join);
char				*ft_strutil(char *dest, const char *src, int util);

#endif
