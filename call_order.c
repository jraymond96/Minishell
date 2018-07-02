/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:40:25 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/02 02:12:52 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

char	*join_path(char *str1, char *str2)
{
	char	*new;
	int		len;

	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	if (!(new = ft_malloc(len + 1)))
		exit (0);
	new[len] = '\0';
	len = -1;
	while (*str1)
	{
		new[++len] = *str1;
		str1++;
	}
	new[++len] = '/';
	while (*str2)
	{
		new[++len] = *str2;
		str2++;
	}
	return (new);
}

int	call_order(char **line, t_list *path, char **envp)
{
	pid_t	ret;
	char	*all_path;

	if (!*line)
		return (0);
	if ((ret = fork()) == -1)
		ft_putstr_fd("fork: error\n", 2);
	if (ret > 0)
	{
		if (wait(NULL) == -1)
			ft_putstr_fd("wait: error\n", 2);
	}
	if (ret == 0)
	{
		if (path)
			all_path = join_path(path->content, *line);
		else
			all_path = join_path(".", *line);
		if (execve(all_path, line, envp) == -1)
			ft_putstr_fd("execve: error\n", 2);
	}
	return (0);
}
