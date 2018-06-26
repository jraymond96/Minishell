/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:40:25 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/26 18:10:54 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	if ((ret = fork()) == -1)
		ft_putstr("limit fork\n");
	if (ret > 0)
	{
		if (wait(NULL) == -1)
			ft_printf("error wait\n");
	}
	if (ret == 0)
	{
		if (path)
			all_path = join_path(path->content, *line);
		else
			all_path = join_path(".", *line);
		if (execve(all_path, line, envp) == -1)
			ft_printf("error execve\n");
	}
	return (0);
}
