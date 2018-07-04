/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_normalpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 06:47:29 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/04 19:09:22 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cd_normalpath(char *param, char **envp)
{
	char	*path;
	char	buf[1024];
	int		ret;

	if (creat_pars_path(&path, param, envp) == -1)
		return (-1);
	ret = ft_strlen(path) - 1;
	if (ret && path[ret] == '/')
		path[ret] = '\0';
	if (!(getcwd(buf, 1024)))
		exit(0);
	if (check_path(path, ft_strlen(path) + 1, param) < 0)
	{
		if (path)
			ft_memdel((void **)&path);
		return (-1);
	}
	if (chdir(path) == -1)
	{
		ft_putstr_fd("error: chdir\n", 2);
		return (-1);
	}
	change_oldpwd(envp, buf);
	ft_memdel((void **)&path);
	return (0);
}
