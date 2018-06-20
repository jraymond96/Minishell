/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:10:36 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/20 11:58:26 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		if_permi_exist(char *path)
{
	DIR	dir;

	opendir
}

int		check_path(char *path, int len)
{
	char	buf[len];
	int		x;
	DIR		dir;

	dir = opendir
	buf[--len] = '\0';
	x = 0;
	ft_memcpy(buf, path, len);
	while (buf[x])
	{
		if (buf[x] == '/' && x != 0)
		{
			buf[x] = '\0';
			if ((len = if_permi_exist(buf)) <= 0)
				return (len);
			buf[x] = '/';
			
		}
		x++;
	}
	if ((len = if_permi(buf)) <= 0)
		return (len);
	return (0);
}
}

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

int		replace_p0byp1(char **path, char **param, char *pwd)
{
	char	*ret;
	int		x;

	x = -1;
	if (!(ret = ft_strstr(pwd, *param)))
	{
		ft_printf("cd: string not in pwd: %s\n", *param);
		return (-2);
	}
	if (!(*path = ft_malloc(len_new_path(pwd, ret, param) + 1)))
		return (-1);
	ft_memcpy(*path, pwd, (ret - pwd));
	ft_strcpy(&(*path)[ret - pwd], param[1]);
	ft_strcpy(&(*path)[ret - pwd + ft_strlen(param[1])], &ret[ft_strlen(*param)]);
	return (0);
}

int		ft_cd(char **param, char **envp)
{
	char	*path;
	char	new_path[1000];
	int		x;
	int		ret;

	x = -1;
	path = NULL;
	if (error_cd(param) == -1)
		return (0);
	while (envp[++x] && ft_memcmp(envp[x], "PWD", 3) != 0)
		;
	if (!envp[x])
		return (0);
	if (len_envp(param) == 2)
	{
		if ((ret = replace_p0byp1(&path, param, &envp[x][4])) == -1)
			return (-1);
		else if (ret == -2)
			return (0);
	}
	else if(!(path = ft_strmidjoin(&envp[x][4], *param, "/")))
		return (-1);
	ft_printf("PWD -> %s\n", path);
	if (chdir(path) == -1)
		return (0);
	getcwd(new_path, 1000);
	ft_printf("PATH -> %s\n", new_path);
	ft_memdel((void **)&path);
	return (0);
}
