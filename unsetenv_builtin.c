/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 06:46:17 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/13 08:02:36 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	int		x;
	int		len;

	x = 0;
	if (ft_strchr(argv[1], '='))
	{
		ft_putstr("Invalid argument\n");
		return (-1);
	}
	len = ft_strlen(argv[1]);
	while((ft_memcmp(envp[x], argv[1], len) != 0 || envp[x][len] != '=') &&
				envp[x])
		x++;
	if (envp[x])
		envp[x] = NULL;
	return (0);
}
