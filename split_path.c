/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 11:35:14 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/21 14:48:54 by jraymond         ###   ########.fr       */
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
	return (i);
}

char	**split_path(char *path)
{
	int		len;
	char	**new;
	int		x;

	if (!(new = ft_malloc(sizeof(char *) * ((len = nb_split(path)) + 1))))
		return (NULL);
	new[len] = NULL;
	len = -1;
	x = -1;
	while (path[++len])
	{
		if (path[len] == '/')
			new[++x] = &path[len];
	}
	return (new);
}
