/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:16:50 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/04 19:17:30 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop_main(char *str, int argc, t_list *path, char ***envcpy)
{
	char	buff[1024];

	buff[0] = '\0';
	if (argc == -1)
	{
		ft_putstr_fd("error: GNL\n", 2);
		exit(0);
	}
	if (check_entry(str) == 0)
	{
		path = handle_path(*envcpy);
		pars_order(str, path, envcpy);
		free_list(&path);
	}
	ft_memdel((void **)&str);
	if (!(getcwd(buff, 1024)))
	{
		ft_putstr_fd("error: getcwd\n", 2);
		exit(0);
	}
	ft_printf("%s%{red}> %{res}", buff);
}

int		main(int argc, char **argv, char **envp)
{
	char	*str;
	t_list	*path;
	char	**envcpy;
	char	buff[1024];

	(void)argv;
	buff[0] = '\0';
	if (!(getcwd(buff, 1024)))
	{
		ft_putstr_fd("error: getcwd\n", 2);
		exit(0);
	}
	ft_printf("%s%{red}> %{res}", buff);
	path = NULL;
	envcpy = cpy_envp(envp);
	while ((argc = get_next_line(0, &str)))
		loop_main(str, argc, path, &envcpy);
	ft_memdel((void **)&str);
	free_split(envcpy);
	free_list(&path);
	return (0);
}
