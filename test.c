/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 01:30:00 by jraymond          #+#    #+#             */
/*   Updated: 2018/06/15 11:26:11 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "minishell.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void	call_unsetenv(char ***envp)
{
	if (!(*envp = malloc(sizeof(char *) * 3)))
		exit(0);
	ft_putstr("TOOT\n");
	*(envp[0]) = ft_strdup("salut ");
	ft_putstr("TOOT\n");
	*(envp[1]) = ft_strdup("comment ");
	//return (setenv(argv[1], argv[2], 1));
	//return (unsetenv(argv[1]));
}

int	main(int argc, char **argv, char **envp)
{
	argc = -1;
	(void)argv;
	/*while (envp[++argc])
		ft_putendl(envp[argc]);*/
	call_unsetenv(&envp);
	while (envp[++argc])
		ft_printf("{%s}", envp[argc]);
	return (0);
	/*ft_putstr("------------------------------------------\n");
	argc = -1;
	while (envp[++argc])
		ft_putendl(envp[argc]);
	return (0);
	if (call_unsetenv(argv) == -1)
	{
		ft_putendl(strerror(errno));
		return (0);
	}
	while (envp[++argc])
		ft_putendl(envp[argc]);
	return (0);*/
}
