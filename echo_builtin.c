/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 08:02:59 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/29 17:51:46 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_all(char **argv)
{
	int	x;
	int	total_len;

	x = -1;
	total_len = 0;
	if (!argv)
		return (0);
	while (argv[++x])
		total_len += (ft_strlen(argv[x]) + 1);
	return (total_len);
		
}

void	join_arg(char **argv, char *line)
{
	int	x;
	int	y;

	x = -1;
	while (argv[++x])
	{
		y = -1;
		while (argv[x][++y])
		{
			*line = argv[x][y];
			line++;
		}
		if ((argv[x + 1]))
		{
			*line = ' ';
			line++;
		}
	}
	*line = '\0';
}

int		ft_echo(char **arg)
{
	int		x;
	char	*line;

	x = ft_strcmp("-n", arg[1]) == 0 ? 1 : 0;
	line = NULL;
	if (x && arg[2])
	{
		if (!(line = malloc(len_all(&arg[2]))))
			exit(0);
		join_arg(&arg[2], line);
		ft_putstr(line);
	}
	else if (!x && arg[1])
	{
		if (!(line = malloc(len_all(&arg[1]))))
			exit(0);
		join_arg(&arg[1], line);
		ft_putendl(line);
	}
	else if (!x)
		ft_putchar('\n');
	if (line)
		free(line);
	return (0);
}
