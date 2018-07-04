/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_oldpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 06:17:15 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/04 18:20:16 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cd_oldpath(char **envp)
{
	int		x;
	char	buf[1024];

	x = -1;
	if (!envp)
		x--;
	if (!(getcwd(buf, 1024)))
		exit(0);
	while (envp[++x] && x != -2 && ft_memcmp(envp[x], "OLDPWD=", 7))
		;
	if (x == -2 || !envp[x] || !envp[x][7])
	{
		ft_putstr_fd("cd: OLDPWD not set\n", 2);
		return (0);
	}
	if (chdir(&envp[x][7]) == -1)
	{
		ft_putstr_fd("error: chdir\n", 2);
		return (0);
	}
	change_oldpwd(envp, buf);
	return (0);
}
