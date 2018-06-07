/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_permi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:07:23 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/07 20:38:09 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_permi(char *path, int len)
{
	char	buf[len];

	buf[--len] = '\0';
	ft_memcpy(buf, path, len);
	ft_printf("path -> %s\n", buf);
	return (0);
}

int		path_permi(char **path)
{
	int	x;

	x = 0;
	while (path[++x])
		check_permi(path[x], (len_path(path[x]) + 1));
	return (0);
}
