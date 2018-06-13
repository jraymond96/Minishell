/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_permi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:07:23 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/13 03:49:06 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		if_permi(char *path)
{
	struct stat	inf;

	if (!*path)
		return (0);
	if (lstat(path, &inf) == -1)
		return (-1);
	if (!(inf.st_mode & S_IXOTH))
		return (-2);
	return (0);
}

int		check_permi(char *path, int len)
{
	char	buf[len];
	int		x;

	buf[--len] = '\0';
	x = 0;
	ft_memcpy(buf, path, len);
	while (buf[x])
	{
		if (buf[x] == '/' && x != 0)
		{
			buf[x] = '\0';
			if (if_permi(buf) == -1)
				return (-1);
			buf[x] = '/';
			
		}
		x++;
	}
	if (if_permi(buf) == -1)
		return (-1);
	return (0);
}

t_list	*path_permi(t_list *path)
{
	int		ret;
	t_list	*begin;

	begin = path;
	while (path)
	{
		if ((ret = check_permi(path->content,
						(len_path(path->content) + 1))) < 0)
		{
			begin = ft_lstrmelem(begin, path);
			if (ret == -1)
			{
				write(2, path->content, len_path(path->content));
				write(2, ": not valide PATH or no permission\n", 35);
			}
			else
			{
				write(2, path->content, len_path(path->content));
				write(2, ": PATH no permission\n", 21);
			}
		}
		path = path->next;
	}
	return (begin);
}
