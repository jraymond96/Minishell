/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:49:44 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/13 06:28:25 by jraymond         ###   ########.fr       */
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

t_list	*take_order(char *shell_line, t_list *paths)
{
	int	x;
	int	y;

	x = 0;
	while(shell_line[x] && shell_line[x] == ' ')
		x++;
	y = x;
	while(shell_line[x] && (shell_line[x] != ';' && shell_line[x] != ' '))
		x++;
	shell_line[x] = '\0'; /* check en premier si il fait partis d un builtin cree */
	return (order_valid(paths, &shell_line[y]));
}

int		check_endstr(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != ';')
			return (1);
		str++;
	}
	return (0);
}

void	pars_order(char *shell_line, t_list *paths, char **envp)
{
	int		x;
	int		len;
	t_list	*good_path;

	x = 0;
	len = ft_strlen(shell_line);
	while (shell_line[x] && shell_line[x] != ';')
		x++;
	good_path = take_order(shell_line, paths);
	if (good_path)
	{
		ft_printf("good_path ->");
		write(1, good_path->content, len_path(good_path->content));
		ft_putchar('\n');
	}
	if (x != len && check_endstr(&shell_line[++x]) == 1)
		pars_order(&shell_line[x], paths, envp);
}
