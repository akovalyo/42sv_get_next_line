/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:00:34 by akovalyo          #+#    #+#             */
/*   Updated: 2020/03/06 20:28:14 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# define BUFF_SIZE 32

char	*rest_text(char *ptr_rest, char **ptr_endl);
int		new_line(const int fd, char **line, char *ptr_rest, char **ptr_endl);
t_list	*new_elem(const int fd);
int		get_next_line(const int fd, char **line);

#endif
