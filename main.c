/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:16:50 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/15 12:27:49 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_path(char *str1, char *str2)
{
	char	*new;
	int		len;

	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	if (!(new = ft_malloc(len + 1)))
		exit (0);
	new[len] = '\0';
	len = -1;
	while (*str1)
	{
		new[++len] = *str1;
		str1++;
	}
	new[++len] = '/';
	while (*str2)
	{
		new[++len] = *str2;
		str2++;
	}
	return (new);
}

int	call_order(char **line, t_list *path, char **envp)
{
	pid_t	ret;
	char	*all_path;

	if ((ret = fork()) == -1)
		ft_putstr("limit fork\n");
	if (ret > 0)
	{
		if (wait(NULL) == -1)
			ft_printf("error wait\n");
	}
	if (ret == 0)
	{
		if (path)
			all_path = join_path(path->content, *line);
		else
			all_path = join_path(".", *line);
		if (execve(all_path, line, envp) == -1)
			ft_printf("error\n");
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_list	*path;
	char	**envcpy;

	(void)argv;
	ft_printf("%7{red}$> %{res}");
	path = NULL;
	envcpy = cpy_envp(envp);
	while ((argc = get_next_line(2, &str)))
	{
		if (argc == -1)
		{
			ft_putstr("GNL failed\n");
			break;
		}
		if (ft_strcmp(str, "exit") == 0)
			break;
		if (check_entry(str) == 0)
			ft_printf("%#{green}%s%{res}\n", str);
		else
			ft_printf("%#{red}!!!! %s !!!!%{res}\n", str);
		path = handle_path(envcpy);
		pars_order(str, path, &envcpy);
		ft_memdel((void **)&str);
		free_list(&path);
		ft_printf("%7{red}$> %{res}");
	}
	ft_memdel((void **)&str);
	free_split(envcpy);
	free_list(&path);
	return (0);
}
