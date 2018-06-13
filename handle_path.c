/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:48:07 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/13 05:20:21 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		how_path(char *path)
{
	int	i;

	i = 1;
	if (!path)
		return (-1);
	while (*path)
	{
		if (*path == ':')
			i++;
		path++;
	}
	if (*(path - 1) == '=')
		return (0);
	return (i);
}

int		len_path(char *str)
{
	int	i;
	
	if (!str)
		return (0);
	i = *str != ':' ? 0 : 1;
	while (*str && *str == ':')
		str++;
	while (*str && *str != ':')
	{
		i++;
		str++;
	}
	return (i);
}

int		cmp_path(char *path1, char *path2)
{
	if (!path1 || !path2)
		return (-1);
	while (*path1 && *path2 && *path1 != ':' && *path2 != ':')
	{
		path1++;
		path2++;
	}
	return ((unsigned char)*path1 - (unsigned char)*path2);
}
