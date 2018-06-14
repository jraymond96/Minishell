/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 06:46:17 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/14 12:25:46 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		tab_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	erase_value(char **envp, char *erase)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (envp[++y])
	{
		if (envp[y] != erase)
			envp[++x] = envp[y];
		else
			envp[++x] = envp[++y];
	}
	envp[x] = NULL;
}

int		ft_unsetenv(char *value, char **envp)
{
	int		x;
	int		len;

	x = 0;
	if (!value || ft_strchr(value, '='))
	{
		ft_putstr("Invalid argument\n");
		return (-1);
	}
	len = ft_strlen(value);
	while ((ft_memcmp(envp[x], value, len) != 0 || envp[x][len] != '=') &&
				envp[x])
		x++;
	if (envp[x])
		erase_value(envp, envp[x]);
	return (0);
}
