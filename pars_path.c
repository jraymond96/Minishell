/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:55:32 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/15 11:15:21 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		if_pathexist(char *paths, t_list *lst_path)
{
	if (!paths)
		return (-1);
	while (lst_path)
	{
		if (cmp_path(paths, lst_path->content) == 0)
			return (-1);
		lst_path = lst_path->next;
	}
	return (0);
}

t_list	*sorting_path(char *path)
{
	int		x;
	char	*tmp;
	t_list	*lst_path;

	x = 0;
	lst_path = NULL;
	path = (path + 5);
	tmp = path;
	while (*path)
	{
		x++;
		if (*path == ':')
		{
			if (if_pathexist(tmp, lst_path) == 0)	
				ft_lstaddback(&lst_path, ft_lstnew(tmp, --x));
			x = 0;
			tmp = (path + 1);
		}
		path++;
	}
	return (lst_path);
}

t_list	*handle_path(char **envp)
{
	t_list	*paths;

	if (!(paths = pars_path(envp)))
	{
		ft_putstr("AUCCUN PATH\n");
		return (NULL);
	}
	paths = path_permi(paths);
	return (paths);
}

t_list	*pars_path(char **envp)
{
	int		x;
	t_list	*path;

	x = 0;
	if (!envp)
		return (NULL);
	while (envp[x] && ft_strncmp(envp[x], "PATH=", 5) != 0)
		x++;
	if (!envp[5] || !envp[x])
		return (NULL);
	path = sorting_path(envp[x]);
	return (path);
}
