/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:00:15 by akovalyo          #+#    #+#             */
/*   Updated: 2020/04/15 13:09:29 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*rest_text(char *content, char **ptr_endl)
{
	char *fline;

	fline = NULL;
	*ptr_endl = ft_strchr(content, '\n');
	if (*ptr_endl)
	{
		fline = ft_subjoin(content, (*ptr_endl - content), content, 0);
		(*ptr_endl)++;
		ft_strutil(content, *ptr_endl, 0);
	}
	else
	{
		fline = ft_strnew(ft_strlen(content) + 1);
		ft_strutil(fline, content, 1);
		ft_bzero(content, ft_strlen(content));
	}
	return (fline);
}

int		new_line(int fd, char **line, char *content, char **buf)
{
	int		byte_read;
	char	*tmp;
	char	*ptr_endl;

	ptr_endl = NULL;
	tmp = NULL;
	*line = rest_text(content, &ptr_endl);
	while (!ptr_endl && ((byte_read = read(fd, *buf, BUFFER_SIZE))
				&& byte_read > 0))
	{
		(*buf)[byte_read] = '\0';
		ptr_endl = ft_strchr(*buf, '\n');
		if (ptr_endl)
		{
			ft_strutil(content, ++ptr_endl, 0);
			ft_bzero(--ptr_endl, 1);
		}
		tmp = *line;
		if (!(*line = ft_subjoin(tmp, 0, *buf, 1)) || byte_read < 0)
			return (-1);
		free(tmp);
	}
	return ((**line == '\0' && !byte_read && !ft_strlen(content)) ? 0 : 1);
}

t_list	*new_elem(int fd)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem->content = ft_strnew(BUFFER_SIZE + 1);
	elem->fd = fd;
	elem->next = NULL;
	return (elem);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*lst;
	t_list			*tmp;
	char			*buf;
	int				res;

	buf = NULL;
	if (fd < 0 || !line || (read(fd, buf, 0)) < 0)
		return (-1);
	buf = ft_strnew(BUFFER_SIZE + 1);
	if (!lst)
		lst = new_elem(fd);
	tmp = lst;
	while (fd != tmp->fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_elem(fd);
		tmp = tmp->next;
	}
	res = new_line(fd, line, tmp->content, &buf);
	free(buf);
	return (res);
}
