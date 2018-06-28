/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:10:36 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/28 16:01:41 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		len_new_path(char *pwd, char *ret, char **param)
{
	int	x;

	x = -1;
	while (pwd[++x] && (pwd + x) != ret)
		;
	pwd += ft_strlen(*param);
	while (pwd[++x])
		;
	x += ft_strlen(param[1]);
	return (x);
}

int		replace_p0byp1(char **path, char **param)
{
	char	*ret;
	char	pwd[1024];
	int		x;

	x = -1;
	getcwd(pwd, 1024);
	if (!(ret = ft_strstr(pwd, *param)))
	{
		ft_printf("cd: string not in pwd: %s\n", *param);
		return (-2);
	}
	if (!(*path = ft_malloc(len_new_path(pwd, ret, param) + 1)))
		return (-1);
	ft_memcpy(*path, pwd, (ret - pwd));
	ft_strcpy(&(*path)[ret - pwd], param[1]);
	ft_strcpy(&(*path)[ret - pwd + ft_strlen(param[1])],
				&ret[ft_strlen(*param)]);
	if (check_path(*path, ft_strlen(*path)) < 0)
		return (-2);
	return (0);
}

int		ft_cd(char **param, char **envp)
{
	char	*path;
	int		x;
	int		ret;

	x = -1;
	path = NULL;
	if (!param)
	{
		if (chdir(&(found_home(envp)[5])) == -1)
			return (-1);
		return (0);
	}
	if (error_cd(param) == -1)
		return (0);
	if (!envp)
		return (0);
	while (envp[++x] && ft_memcmp(envp[x], "PWD", 3) != 0)
		;
	if (len_envp(&param[1]) == 2)
	{
		if ((ret = replace_p0byp1(&path, param)) == -1)
			return (-1);
		else if (ret == -2)
			return (0);
	}
	else
	{
		if (creat_pars_path(&path, *param, envp) == -1)
			return (-1);
	}
	if (path[ft_strlen(path) - 1] == '/')
		path[ft_strlen(path) - 1] = '\0';
	if (check_path(path, (ft_strlen(path) + 1)) < 0)
		return (0);
	if (chdir(path) == -1)
		return (-1);
	ft_memdel((void **)&path);
	return (0);
}
