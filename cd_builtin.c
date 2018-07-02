/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:10:36 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/02 05:54:04 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_cd(char **param, char **envp)
{
	int	ret;

	ret = ret_fonc_cd(param);
	if (ret == 1)
		cd_no_arg(envp);
	else if (ret == 2)
		cd_two_args(param, envp);
	return (0);
}

/*int		ft_cd(char **param, char **envp)
{
	char	*path;
	int		x;
	int		ret;

	x = -1;
	path = NULL;
	ret = ret_fonc_cd(param);
	if (!param)
	{
		if (envp && chdir(&(found_home(envp)[5])) == -1)
			return (-1);
		ft_putstr_fd("cd: HOME not set\n", 2);
		return (0);
	}
	if (error_cd(param) == -1)
		return (0);
	while (envp && envp[++x] && ft_memcmp(envp[x], "PWD", 3) != 0)
		;
	if (len_envp(param) == 2)
	{
		if ((ret = replace_p0byp1(&path, param)) == -1)
			return (-1);
		else if (ret == -2)
			return (0);
	}
	else
	{
		if ((*param)[0] != '-' && creat_pars_path(&path, *param, envp) == -1)
			return (-1);
	}
	x = 0;
	while (envp && envp[++x] && ft_memcmp(envp[x], "OLDPWD", 6) != 0)
		;
	if (envp[x])
	{
		free(envp[x]);
		if (!(envp[x] = (char *)ft_malloc((ft_strlen(path) + 8))))
			exit(0);
		ft_mem2join(envp[x], "OLDPWD=", path, ft_strlen(path));
	}
	if (*param[0] == '-')
		path = ft_strdup(&envp[x][7]);
	else if (path[(ret = ft_strlen(path)) - 1] == '/' && ret != 1)
		path[ft_strlen(path) - 1] = '\0';
	if ((*param)[0] != '-' && check_path(path, (ft_strlen(path) + 1), *param) < 0)
		return (0);
	if (chdir(path) == -1)
		return (-1);
	ft_memdel((void **)&path);
	return (0);
}*/
