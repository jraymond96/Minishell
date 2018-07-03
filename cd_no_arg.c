/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_no_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 05:04:43 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/03 03:22:52 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		bis(char **envp, int x)
{
	int	len;

	len = ft_strlen(&envp[x][5]);
	if (check_path(&envp[x][5], len + 1, NULL))
		return (-1);
	if (chdir(&(envp[x][5])) == -1)
		ft_putstr_fd("error: chdir\n", 2);
	return (0);
}

int		cd_no_arg(char **envp)
{
	int		x;
	char	buf[1024];

	x = -1;
	if (!envp)
		x--;
	if (!(getcwd(buf, 1024)))
		exit(0);
	while (x != -2 && ft_memcmp(envp[++x], "HOME=", 5) != 0)
		;
	if (x < 0 || !envp[x])
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		return (0);
	}
	else
	{
		if (bis(envp, x) == -1)
			return (-1);
	}
	change_oldpwd(envp, buf);
	return (0);
}
