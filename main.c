/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:16:50 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/02 05:53:49 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_list	*path;
	char	**envcpy;
	char	buff[1024];

	(void)argv;
	ft_printf("%s%{red}> %{res}", getcwd(buff, 1024));
	path = NULL;
	envcpy = cpy_envp(envp);
	while ((argc = get_next_line(2, &str)))
	{
		if (argc == -1)
		{
			ft_putstr_fd("GNL failed\n", 2);
			break;
		}
		if (check_entry(str) == 0)
		{
			path = handle_path(envcpy);
			pars_order(str, path, &envcpy);
			free_list(&path);
		}
		ft_memdel((void **)&str);
		ft_printf("%s%{red}> %{res}", getcwd(buff, 1024));
	}
	ft_memdel((void **)&str);
	free_split(envcpy);
	free_list(&path);
	return (0);
}
