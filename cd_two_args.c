/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_two_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 05:29:27 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/03 03:34:21 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		len_new_path(char *pwd, char *ret, char **param)
{
	int	x;

	x = -1;
	while (pwd[++x] && (pwd + x) != ret)
		;
	pwd += ft_strlen(*param);
	while (pwd[++x])
		;
	x += ft_strlen(param[1]);
	return (x);
}

int		replace_p0byp1(char **path, char **param)
{
	char	*ret;
	char	pwd[1024];
	int		x;

	x = -1;
	if (!(getcwd(pwd, 1024)))
	{
		ft_putstr_fd("getcwd: error\n", 2);
		return (-1);
	}
	if (!(ret = ft_strstr(pwd, *param)))
	{
		ft_printf("cd: string not in pwd: %s\n", *param);
		return (-2);
	}
	if (!(*path = (char *)ft_malloc(len_new_path(pwd, ret, param) + 1)))
		exit(0);
	ft_memcpy(*path, pwd, (ret - pwd));
	ft_strcpy(&(*path)[ret - pwd], param[1]);
	ft_strcpy(&(*path)[ret - pwd + ft_strlen(param[1])],
				&ret[ft_strlen(*param)]);
	if (check1_path(*path, ft_strlen(*path), *param) < 0)
		return (-2);
	return (0);
}

int		cd_two_args(char **param, char **envp)
{
	char	*path;
	char	buf[1024];

	path = NULL;
	if (replace_p0byp1(&path, param) < 0)
		return (-1);
	ft_memdel((void **)&path);
	if (!(getcwd(buf, 1024)))
		exit(0);
	change_oldpwd(envp, buf);
	return (0);
}
