/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:55:32 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/08 17:24:26 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	empty_paths(char **paths, char *path)
{
	int	x;

	x = 1;
	*paths = (path + 5);
	while (*path)
	{
		if (*path == ':')
			paths[x++] = (path + 1);
		path++;
	}
}

int		remove_double(char **paths, int len_paths)
{
	int	x;
	int	y;

	x = 0;
	while (x < len_paths)
	{
		y = 0;
		while (paths[x] && y < len_paths)
		{
			if (x != y && cmp_path(paths[y], paths[x]) == 0)
				paths[y] = NULL;
			y++;
		}
		x++;
	}
	y = 0;
	x = 0;
	while (x < len_paths)
	{
		if (paths[x++])
			y++;
	}
	return (y);
}

t_list	*sorting_path(char *path, int nb_path)
{
	char	*paths[nb_path];
	t_list	*list;
	int		x;
	int		len;
	
	x = 0;
	paths[--nb_path] = NULL;
	empty_paths(paths, path);
	len = remove_double(paths, nb_path);
	while (x < nb_path)
	{
		if (paths[x])
			ft_lstaddback(&list, ft_lstnewnocpy((paths[x])));
		x++;
	}
	return (list);
}


t_list	*pars_path(char **envp)
{
	int		x;
	t_list	*path;
	t_list	*elem;

	x = 0;
	while (ft_strncmp(envp[x], "PATH=", 5) != 0)
		x++;
	if (!envp[5] || !envp[x])
		return (NULL);
	path = sorting_path(envp[x], (how_path(envp[x]) + 1));
	elem = path;
	while (elem)
	{
		write(1, elem->content, len_path(elem->content));
		ft_putchar('\n');
		elem = elem->next;
	}
	return (path);
}
