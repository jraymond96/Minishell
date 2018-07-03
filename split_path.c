/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 11:35:14 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/03 03:54:08 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		nb_split(char *path)
{
	int	i;

	i = 0;
	while (*path)
	{
		if (*path == '/')
			i++;
		path++;
	}
	return (i = i == 0 ? 1 : i);
}

char	**split_path(char *path)
{
	int		len;
	char	**new;
	int		x;

	len = nb_split(path);
	if (!(new = ft_malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	new[len] = NULL;
	len = -1;
	x = -1;
	while (path[++len])
	{
		if (path[len] == '/' || len == 0)
			new[++x] = &path[len];
	}
	return (new);
}
