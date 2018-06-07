/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_permi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:07:23 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/07 21:44:43 by jraymond         ###   ########.fr       */
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
		return (-1);
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

int		path_permi(char **path)
{
	int	x;

	x = 0;
	while (path[++x])
	{
		if (check_permi(path[x], (len_path(path[x]) + 1)) == -1)
			ft_printf("PATH:{%s} not valide\n", path[x]);
	}
	return (0);
}
