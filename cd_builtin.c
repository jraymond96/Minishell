/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:10:36 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/20 15:41:34 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_first_folder(char *buf)
{
	int			x;
	int			flag;
	struct stat stats;

	x = 0;
	flag = 0;
	while (buf[++x] && buf[x] != '/')
		;
	if (!buf[x])
		flag++;
	buf[x] = '\0';
	if (lstat(buf, &stats) == -1)
	{
		ft_printf("cd: no such file or directory: %s\n", buf);
		return (-1);
	}
	else if (!(stats.st_mode & S_IXOTH))
	{
		ft_printf("cd: permission denied: %s\n", buf);
		return (-1);
	}
	if (!flag)
		buf[x] = '/';
	return (0);
}

int		folder_exist(DIR *dir, int len, char *folder, char *path)
{
	struct dirent	*info;

	while ((info = readdir(dir)))
	{
		if (ft_memcmp(info->d_name, folder, len) == 0)
			break;
	}
	if (!info)
	{
		ft_printf("cd: no such file or directory: %s\n", path);
		return (-1);
	}
	if (if_permi(path) == -2)
	{
		ft_printf("cd: permission denied: %s\n", path);
		return (-1);
	}
	return (0);
}

int		if_exist_permi(char *path, DIR *dir)
{
	int				len;
	char			*tmp;
	int				flag;

	tmp = path;
	flag = 0;
	while ((len = ft_strclen(path, '/')) && !flag)
	{
		if (!path[len])
			flag++;
		path[len] = '\0';
		if (folder_exist(dir, len, path, tmp) != 0)
			return (-1);
		if (!(dir = opendir(tmp)))
		{
			ft_putstr("error opendir\n");
			return (-2);
		}
		if (!flag)
			path[len] = '/';
		path += len;
	}
	return (0);
}

int		check_path(char *path, int len)
{
	char		buf[len];
	int			x;
	DIR			*dir;

	buf[--len] = '\0';
	x = -1;
	ft_memcpy(buf, path, len);
	if (check_first_folder(buf) == -1)
		return (-2);
	if (!(dir = opendir(buf)))
		return (-1);
	if ((len = if_exist_permi(&buf[x], dir)) < 0)
		return (-2);
	return (0);
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
	ft_strcpy(&(*path)[ret - pwd + ft_strlen(param[1])],
				&ret[ft_strlen(*param)]);
	if (check_path(*path, ft_strlen(*path)) < 0)
		return (-2);
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
	if (check_path(path, ft_strlen(path)) < 0)
		return (0);
	if (chdir(path) == -1)
		return (0);
	getcwd(new_path, 1000);
	ft_printf("PATH -> %s\n", new_path);
	ft_memdel((void **)&path);
	return (0);
}
