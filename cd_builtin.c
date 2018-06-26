/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:10:36 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/26 17:06:13 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		back_path(char **path, char *pwd)
{
	char	*last_ocu;

	last_ocu = ft_strrchr(pwd, '/');
	*last_ocu = '\0';
	if (!(*path = ft_strdup(pwd)))
		return (-1);
	return (0);
}

char	*found_home(char **envp)
{
	int	x;

	x = -1;
	while (envp[++x] && ft_memcmp(envp[x], "HOME", 4) != 0);
	return (envp[x]);
}

void	rm_lastfolder(char *buff)
{
	char	*last_ocu;

	if ((last_ocu = ft_strrchr(buff, '/')))
		*last_ocu = '\0';
	if ((last_ocu = ft_strrchr(buff, '/')))
		*(last_ocu + 1) = '\0';
}

int		absolute_path(char **path, char *param, char *buff)
{
	char	**split;
	int		x;

	if (!(split = split_path(param)))
		return (-1);
	x = -1;
	while (split[++x])
	{
		if (ft_memcmp(&split[x][1], "..", 2) != 0)
		{
			if (x == 0)
				ft_memcpy(buff, split[x], (ft_strclen(&split[x][1], '/') + 1));
			else
				ft_memcpy(&buff[ft_strlen(buff)], &split[x][1],
							ft_strclen(&split[x][1], '/'));
			ft_strcpy(&buff[ft_strlen(buff)], "/");
		}
		else
			rm_lastfolder(buff);
	ft_printf("_path_ -> %s\n", buff);
	}
	if (!(*path = ft_strdup(buff)))
		return (-1);
	free(split);
	return (0);
}

int		creat_pars_path(char **path, char *param)
{
	char	pwd[1024];
	char	buff[1024];
	char	new_path[1024];

	getcwd(pwd, 1024);
	first_char_cd(new_path, param, pwd);
	if (!param)
	{
		ft_putstr("titi 0\n");
		*path = ft_strdup(pwd);
	}
	ft_printf("new_path -> %s\n", new_path);
	absolute_path(path, new_path, buff);
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
	char	test[1024];

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
		if ((ret = replace_p0byp1(&path, param)) == -1)
			return (-1);
		else if (ret == -2)
			return (0);
	}
	else
	{
		if (creat_pars_path(&path, *param) == -1)
			return (-1);
	}
	if (check_path(path, (ft_strlen(path) + 1)) < 0)
		return (0);
	if (chdir(path) == -1)
		return (-1);
	ft_memdel((void **)&path);
	ft_printf("act_pwd -> %s\n", getcwd(test, 1024));
	return (0);
}
