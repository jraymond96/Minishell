/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_char_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:27:15 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/03 02:07:23 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		back_folder(char *pwd, char *param, char *buff)
{
	char	*last_ocu;

	last_ocu = ft_strrchr(pwd, '/');
	if (last_ocu)
	{
		if (last_ocu == pwd)
			*(last_ocu + 1) = '\0';
		else
			*last_ocu = '\0';
	}
	ft_mem2join(buff, pwd, &param[2], ft_strlen(&param[1]));
	return (0);
}

int		home_dest(char *buff, char *home, char *param)
{
	if (!home || !home[5])
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		return (-1);
	}
	ft_mem2join(buff, &home[5], &param[1], ft_strlen(&param[1]));
	return (0);
}

int		first_char_cd(char *buff, char *param, char *pwd, char *home)
{
	if (*param == '~')
		return (home_dest(buff, home, param));
	else if (ft_memcmp(param, "..", 2) == 0)
		return (back_folder(pwd, param, buff));
	else if (*param == '/')
		ft_strcpy(buff, param);
	else if (ft_memcmp(param, "./", 2) == 0)
		ft_mem2join(buff, pwd, &param[1], ft_strlen(&param[1]));
	else if (*param != '/')
	{
		ft_strcpy(buff, pwd);
		ft_strcpy(&buff[ft_strlen(buff)], "/");
		ft_strcpy(&buff[ft_strlen(buff)], param);
	}
	return (0);
}
