/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_valid_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:43:08 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/04 18:09:57 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		access_order(char *path, char *order, int len, int len_order)
{
	char	new_path[len + len_order + 2];
	int		i;

	new_path[len + len_order + 1] = '\0';
	ft_memcpy(new_path, path, (len));
	new_path[len] = '/';
	ft_memcpy(&new_path[len + 1], order, len_order);
	i = len + len_order + 2;
	return (access(new_path, F_OK));
}

t_list	*order_valid(t_list *paths, char *order)
{
	int ret;

	ret = -1;
	while (paths && ret != 0)
	{
		ret = access_order(paths->content, order, len_path(paths->content),
								ft_strlen(order));
		if (ret == 0)
			return (paths);
		paths = paths->next;
	}
	ft_dprintf(2, "zsh: command not found: %s\n", order);
	return (NULL);
}

int		thats_builtin(char *order)
{
	if (ft_strcmp(order, "cd") == 0)
		return (1);
	else if (ft_strcmp(order, "env") == 0)
		return (1);
	else if (ft_strcmp(order, "exit") == 0)
		return (1);
	else if (ft_strcmp(order, "echo") == 0)
		return (1);
	else if (ft_strcmp(order, "unsetenv") == 0)
		return (1);
	else if (ft_strcmp(order, "setenv") == 0)
		return (1);
	else if (*order == '/' || ft_memcmp(order, "./", 2) == 0)
		return (1);
	else
		return (0);
}

t_list	*if_valid_order(t_list *paths, char *shell_line, int *ret)
{
	int		x;
	char	*order;
	int		ret1;

	x = 0;
	ret1 = 0;
	while (*shell_line && (*shell_line == ' ' || *shell_line == '\t'))
		shell_line++;
	while (shell_line[x] && shell_line[x] != ';' && shell_line[x] != ' ')
		x++;
	if (!(order = ft_memdup(shell_line, x)))
		exit(0);
	if (!paths && thats_builtin(order) != 1 && *shell_line)
	{
		ft_dprintf(2, "zsh: command not found: %s\n", order);
		ret1++;
	}
	else if ((*ret = is_builtin(order)) > 0)
		ret1++;
	else if (ret1 == 0)
		paths = order_valid(paths, order);
	free(order);
	if (ret1 == 1)
		return (NULL);
	return (paths);
}
