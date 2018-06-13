/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:16:50 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/13 07:46:26 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	call(char **av)
{
	pid_t	ret;

	if ((ret = fork()) == -1)
		ft_putstr("limit fork\n");
	if (ret > 0)
	{
		if (wait(NULL) == -1)
			ft_printf("error wait\n");
		ft_printf("exec du pere\n");
	}
	if (ret == 0)
	{
		if (execve("/bin/ls", av, NULL) == -1)
			ft_printf("error\n");
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_list	*path;

	(void)argv;
	ft_printf("%7{red}$> %{res}");
	path = NULL;
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
		path = handle_path(envp);
		pars_order(str, path, envp);
		ft_memdel((void **)&str);
		ft_printf("%7{red}$> %{res}");
	}
	ft_memdel((void **)&str);
	free_list(&path);
	return (0);
}
