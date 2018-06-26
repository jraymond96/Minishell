/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_handle_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:30:45 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/26 17:02:09 by jraymond         ###   ########.fr       */
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
		{
			ft_printf("MATCH PATH: %s || FOLDER: %s\n", path, folder);
			break;
		}
	}
	if (!info)
	{
		folder[-1] = '/';
		ft_printf("cd: no such file or directory: %s\n", path);
		return (-1);
	}
	if (if_permi(path) == -2)
	{
		folder[-1] = '/';
		ft_printf("cd: permission denied: %s\n", path);
		return (-1);
	}
	return (0);
}

int		if_exist_permi(char *path, DIR *dir)
{
	char	**split;
	int		x;
	int		len;

	split = split_path(path);
	x = -1;
	while (split[++x] && split[x + 1])
	{
		split[x + 1][ft_strclen(split[x + 1], '/')] = '\0';
		len = ft_strclen(&split[x + 1][1], '/');
		if (folder_exist(dir, len, &split[x + 1][1], *split) != 0)
			return (-1);
		if (split[x + 2])
		{
			split[x + 1][ft_strclen(split[x + 1], '/')] = '/';
			split[x + 2][ft_strclen(split[x + 2], '/')] = '\0';
		}
		closedir(dir);
		if (!(dir = opendir(*split)))
			return (-2);
	}
	closedir(dir);
	free(split);
	return (0);
}

int		check_path(char *path, int len)
{
	char		buf[len];
	DIR			*dir;
	char		*ret;
	char		tmp;

	buf[--len] = '\0';
	ft_memcpy(buf, path, len);
	if (check_first_folder(buf) == -1)
		return (-2);
	if ((ret = ft_strchr(&buf[1], '/')))
	{
		tmp = *(ret + 1);
		*(ret + 1) = '\0';
	}
	if (!(dir = opendir(buf)))
		return (-1);
	if (ret)
		*(ret + 1) = tmp;
	if ((len = if_exist_permi(buf, dir)) < 0)
	{
		closedir(dir);
		return (-2);
	}
	return (0);
}
