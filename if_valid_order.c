/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_valid_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:43:08 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/15 10:30:42 by jraymond         ###   ########.fr       */
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
	ft_printf("zsh: command not found: %s\n", order);
	return (NULL);
}

t_list	*if_valid_order(t_list *paths, char *shell_line, int *ret)
{
	int		x;
	char	*order;

	x = 0;
	while (*shell_line == ' ')
		shell_line++;
	while (shell_line[x] && shell_line[x] != ';' && shell_line[x] != ' ')
		x++;
	order = ft_memdup(shell_line, x);
	if (!paths)
	{
		ft_printf("zsh: command not found: %s\n", order);
		return (NULL);
	}
	if ((*ret = is_builtin(order)) > 0)
	{
		free(order);
		return (NULL);
	}
	else
		paths = order_valid(paths, order);
	free(order);
	return (paths);
}
