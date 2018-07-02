/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 06:22:11 by jraymond          #+#    #+#             */
/*   Updated: 2018/07/03 00:24:00 by jraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**if_name(char *arg, char **envp)
{
	int	x;
	int	len;

	x = -1;
	len = ft_strlen(arg);
	if (!envp)
		return (NULL);
	while (envp[++x])
	{
		if (ft_memcmp(envp[x], arg, len) == 0)
			return (&envp[x]);
	}
	return (NULL);
}

char	**add_namevalue(char *name, char *value, char ***envp)
{
	int		len;
	int		x;
	char	**new;
	char	*name_value;

	len = 0;
	x = 0;
	if (!(name_value = ft_strmidjoin(name, value, "=")))
		exit(0);
	if (!(new = cpy_envp1(*envp)))
		exit(0);
	while (new[x])
		x++;
	new[x] = name_value;
	if (*envp)
		free_split(*envp);
	*envp = new;
	return (new);
}

char	*change_value(char *value, char **envp, int size)
{
	char	*new;
	int		len;

	if (!value)
	{
		(*envp)[size + 1] = '\0';
		return (*envp);
	}
	if (!(new = ft_malloc((size + 1) + (len = ft_strlen(value)) + 1)))
		exit (0);
	ft_memcpy(new, *envp, (size + 1));
	ft_strcpy(&new[size + 1], value);
	ft_memdel((void **)envp);
	new[len + size + 1] = '\0';
	*envp = new;
	return (new);
}

int		ft_setenvnull(char **arg, char ***envp)
{
	char	**name;

	if (!(name = if_name(arg[1], *envp)))
	{
		if (!add_namevalue(arg[1], NULL, envp))
			return (-1);
	}
	else if (name && arg[2] && *arg[2] != '0' && ft_strlen(arg[2]) == 1)
	{
		if (!change_value(NULL, name, ft_strclen(*name, '=')))
			return (-1);
	}
	return (0);
}
int		ft_setenv(char **arg, char ***envp)
{
	char	**name;
	int		ret;

	if ((ret = error_setenv(arg)) == 0)
	{
		if (!(name = if_name(arg[1], *envp)))
			add_namevalue(arg[1], arg[2], envp);
		else if (name && arg[3] && *arg[3] != '0' && ft_strlen(arg[3]) == 1)
			change_value(arg[2], name, ft_strclen(*name, '='));
		return (0);
	}
	if (ret == -1)
		return (-2);
	else
		return (ft_setenvnull(arg, envp));
}
