/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:30:47 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/29 19:50:17 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	call_bin(char **line, char *path, char **envp)
{
	pid_t	ret;

	if ((ret = fork()) == -1)
		ft_putstr_fd("fork: error\n", 2);
	if (ret > 0)
	{
		if (wait(NULL) == -1)
			ft_putstr_fd("wait: error\n", 2);
	}
	if (ret == 0)
	{
		if (execve(path, line, envp) == -1)
			ft_putstr_fd("execve: error\n", 2);
	}
	return (0);
}

int		ft_bin(char **param, char **envp)
{
	char	*path;
	int		ret;

	if (creat_pars_path(&path, *param, envp) == -1)
		return (-1);
	if (check_path(path, (ft_strlen(path) + 1), *param) < 0)
		return (0);
	ret = ft_strlen(path) - 1;
	if (path[ret] == '/')
		path[ret] = '\0';
	if (call_bin(&param[1], path, envp) == -1)
		return (-1);
	return (0);
}