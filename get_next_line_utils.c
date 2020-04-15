/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 09:27:33 by akovalyo          #+#    #+#             */
/*   Updated: 2020/04/15 13:21:06 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_subjoin(char const *s, int len, char const *s2, int join)
{
	char	*fresh;
	int		i;

	if (!s || !s2)
		return (NULL);
	if (join)
	{
		if (!(fresh = (char *)malloc(ft_strlen(s) + ft_strlen(s2) + 1)))
			return (NULL);
		ft_strutil(fresh, s, 0);
		ft_strutil(fresh, s2, 1);
	}
	else
	{
		i = 0;
		if (!(fresh = (char *)malloc(len + 1)))
			return (NULL);
		while (i < len)
		{
			fresh[i] = s[i];
			i++;
		}
		fresh[i] = '\0';
	}
	return (fresh);
}

char	*ft_strutil(char *dest, const char *src, int util)
{
	int len;
	int i;

	i = 0;
	if (!util)
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	else
	{
		len = ft_strlen(dest);
		while (src[i])
		{
			dest[len] = src[i];
			len++;
			i++;
		}
		dest[len] = '\0';
	}
	return (dest);
}

void	ft_bzero(void *s, int n)
{
	char *tmp;

	tmp = (char*)s;
	while (n > 0)
	{
		*tmp = '\0';
		n--;
		tmp++;
	}
}

char	*ft_strnew(int size)
{
	char *f;

	f = (char *)malloc(sizeof(char) * size);
	if (f == NULL)
		return (NULL);
	ft_bzero(f, size);
	return (f);
}

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
