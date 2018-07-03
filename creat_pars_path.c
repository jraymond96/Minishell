/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_pars_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:25:19 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/03 03:16:26 by jraymond         ###   ########.fr       */
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

void	rm_lastfolder(char *buff)
{
	char	*last_ocu;

	if ((last_ocu = ft_strrchr(buff, '/')))
		*last_ocu = '\0';
	if ((last_ocu = ft_strrchr(buff, '/')))
		*(last_ocu + 1) = '\0';
}

int		if_doublepoint(char *buff, char **split, int x)
{
	int total;
	int	len;

	len = ft_strclen(&split[x][1], '/');
	total = ft_strlen(buff);
	if (x == 0)
		ft_memcpy(buff, split[x], (len + 1));
	else if (split[x][1] != '.' || ft_strclen(&split[x][1], '/') != 1)
		ft_memcpy(&buff[ft_strlen(buff)], &split[x][1], len);
	len += x == 0 ? total + 1 : total;
	if (ft_strlen(buff) != 1)
		ft_strcpy(&buff[len], "/");
	else
		buff[len] = '\0';
	return (0);
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
			if_doublepoint(buff, split, x);
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

	if (!(getcwd(pwd, 1024)))
	{
		ft_putstr_fd("error: getcwd\n", 2);
		exit(0);
	}
	x = -1;
	buff[0] = '\0';
	if (first_char_cd(new_path, param, pwd, found_home(envp)) == -1)
		return (-1);
	if (!param)
	{
		if (!(*path = ft_strdup(pwd)))
			exit(0);
	}
	if (absolute_path(path, new_path, buff) == -1)
		exit(0);
	return (0);
}
