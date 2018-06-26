/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_char_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:27:15 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/26 16:35:46 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	first_char_cd(char *buff, char *param, char *pwd)
{
	char	*last_ocu;
	if (*param == '~')
		ft_mem2join(buff, pwd, &param[1], ft_strlen(&param[1]));
	else if (ft_memcmp(param, "..", 2) == 0)
	{
		last_ocu = ft_strrchr(pwd, '/');
		if (last_ocu)
			*last_ocu = '\0';
		ft_mem2join(buff, pwd, &param[2], ft_strlen(&param[1]));
	}
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
}
