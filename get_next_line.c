/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:00:15 by akovalyo          #+#    #+#             */
/*   Updated: 2020/03/06 15:33:38 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*rest_text(char *content, char **ptr_endl)
{
	char *fline;
	
	fline = NULL;
	*ptr_endl = ft_strchr(content, '\n');
	if (*ptr_endl != NULL)
	{
		fline = ft_strsub(content, 0, (*ptr_endl - content));
		(*ptr_endl)++;
		ft_strcpy(content, *ptr_endl);
	}
	else
	{
		fline = ft_strnew(ft_strlen(content) + 1);
		ft_strcat(fline, content);
		ft_strclr(content);
	}
	return (fline);
}

int			new_line(int fd, char **line, char *content, char **buf)
{
	int		byte_read;
	char	*tmp;
	char	*ptr_endl;

	ptr_endl = NULL;
	tmp = NULL;
	*line = rest_text(content, &ptr_endl);
	while (!ptr_endl && ((byte_read = read(fd, *buf, BUFF_SIZE))))
	{
		(*buf)[byte_read] = '\0';
		ptr_endl = ft_strchr(*buf, '\n');
		if (ptr_endl)
		{
			ptr_endl++;
			ft_strcpy(content, ptr_endl);
			ptr_endl--;
			ft_strclr(ptr_endl);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, *buf)) || byte_read < 0)
			return (-1);
		free(tmp);
	}
	return (**line == '\0' && !byte_read && !ft_strlen(content)) ? 0 : 1;
	//if (ft_strlen(content) || ft_strlen(*line) || byte_read)
	//	return (1);
	//else
	//	return (0);
}

t_list	*new_elem(int fd)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem->content = ft_strnew(BUFF_SIZE);
	elem->content_size = (size_t)fd;
	elem->next = NULL;
	return (elem);
}

int			get_next_line(int fd, char **line)
{
	static t_list	*lst;
	t_list		*tmp;
	char			*ptr_endl;
	char *buf;
	int res;

	ptr_endl = NULL;
	buf = NULL;
	//buf = ft_memalloc(BUFF_SIZE + 1);
	//ft_bzero(buf, BUFF_SIZE + 1);
	if (fd < 0 || !line || (read(fd, buf, 0)) < 0)
		return (-1);
	buf = ft_memalloc(BUFF_SIZE + 1);
	if (!lst)
		lst = new_elem(fd);
	tmp = lst;
	while (fd != (int)tmp->content_size)
	{
		if (tmp->next == NULL)
			tmp->next = new_elem(fd);
		tmp = tmp->next;
	}
	res = new_line(fd, line, tmp->content, &buf);
	//ft_bzero(buf, BUFF_SIZE + 1);
	//ft_strdel(&buf);
	free(buf);
	return (res);
}
