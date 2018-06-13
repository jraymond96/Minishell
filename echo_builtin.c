/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 08:02:59 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/13 08:49:12 by jraymond         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		x;
	char	*line;

	x = 1;
	argc = ft_strcmp("-n", argv[1]) == 0 ? 1 : 0;
	line = NULL;
	if (argc && argv[2])
	{
		line = malloc(len_all(&argv[2]));
		join_arg(&argv[2], line);
		ft_putstr(line);
	}
	else if (!argc && argv[1])
	{
		line = malloc(len_all(&argv[1]));
		join_arg(&argv[1], line);
		ft_putendl(line);
	}
	if (line)
		free(line);
	return (0);
}
