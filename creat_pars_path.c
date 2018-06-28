/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_pars_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:25:19 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/28 15:43:18 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*found_home(char **envp)
{
	int	x;

	x = -1;
	while (envp[++x] && ft_memcmp(envp[x], "HOME", 4) != 0);
	return (envp[x]);
}

int		back_path(char **path, char *pwd)
{
	char	*last_ocu;

	last_ocu = ft_strrchr(pwd, '/');
	*last_ocu = '\0';
	if (!(*path = ft_strdup(pwd)))
		return (-1);
	return (0);
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
	int		len;
	int		total;

	if (!(split = split_path(param)))
		return (-1);
	x = -1;
	while (split[++x])
	{
		if (ft_memcmp(&split[x][1], "..", 2) != 0)
		{
			len = ft_strclen(&split[x][1], '/');
			total = ft_strlen(buff);
			if (x == 0)
				ft_memcpy(buff, split[x], (len + 1));
			else if (split[x][1] != '.' || ft_strclen(&split[x][1], '/') != 1)
				ft_memcpy(&buff[ft_strlen(buff)], &split[x][1], len);
			len += x == 0 ? total + 1 : total;
			ft_strcpy(&buff[len], "/");
		}
		else 
			rm_lastfolder(buff);
	}
	if (!(*path = ft_strdup(buff)))
		return (-1);
	free(split);
	return (0);
}

int		creat_pars_path(char **path, char *param, char **envp)
{
	char	pwd[1024];
	char	buff[1024];
	char	new_path[1024];
	int		x;

	getcwd(pwd, 1024);
	x = -1;
	buff[0] = '\0';
	if (first_char_cd(new_path, param, pwd, found_home(envp)) == -1)
	{
		ft_putstr("cd: HOME not set\n");
		return (-1);
	}
	if (!param)
		*path = ft_strdup(pwd);
	absolute_path(path, new_path, buff);
	return (0);
}
