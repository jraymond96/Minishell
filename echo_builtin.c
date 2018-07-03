/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 08:02:59 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/03 21:05:13 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*found_envp(char **envp, char *arg)
{
	int	len;
	int	x;

	if ((len = ft_strlen(arg)) == 0)
		return (NULL);
	x = -1;
	while (envp[++x] && ft_memcmp(envp[x], arg, len) != 0)
		;
	if (envp[x])
		return (&envp[x][len]);
	else
		return (NULL);
}

int		len_all(char **argv, char **envp)
{
	int		x;
	int		total_len;
	char	*ret;

	x = -1;
	total_len = 0;
	if (!argv)
		return (0);
	while (argv[++x])
	{
		if (argv[x][0] == '$')
		{
			ret = found_envp(envp, &argv[x][1]);
			total_len += ft_strlen(ret);
		}
		else
			total_len += (ft_strlen(argv[x]) + 1);
	}
	return (total_len);
}

char	*dollars(int x, char **argv, char **envp, char *line)
{
	char *ret;

	ret = found_envp(envp, &argv[x][1]);
	if (ret)
	{
		ft_strcpy(line, ret + 1);
		line += ft_strlen(ret) - 1;
	}
	return (line);
}

void	join_arg(char **argv, char *line, char **envp)
{
	int		x;
	int		y;

	x = -1;
	while (argv[++x])
	{
		y = -1;
		while (argv[x][++y] && argv[x][y] != '$')
		{
			*line = argv[x][y];
			line++;
		}
		if (argv[x][y] == '$')
			line = dollars(x, argv, envp, line);
		if ((argv[x + 1]))
		{
			*line = ' ';
			line++;
		}
	}
	*line = '\0';
}

int		ft_echo(char **arg, char **envp)
{
	int		x;
	char	*line;

	(void)envp;
	x = ft_strcmp("-n", arg[1]) == 0 ? 1 : 0;
	line = NULL;
	if (x && arg[2])
	{
		if (!(line = malloc(len_all(&arg[2], envp))))
			exit(0);
		join_arg(&arg[2], line, envp);
		ft_putstr(line);
	}
	else if (!x && arg[1])
	{
		if (!(line = malloc(len_all(&arg[1], envp))))
			exit(0);
		join_arg(&arg[1], line, envp);
		ft_putendl(line);
	}
	else if (!x)
		ft_putchar('\n');
	if (line)
		free(line);
	return (0);
}
