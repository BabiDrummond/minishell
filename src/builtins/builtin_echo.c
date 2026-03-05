/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:42:57 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/21 19:14:19 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_n_option(char *arg)
{
	int	i;

	i = 1;
	if (!arg || arg[0] != '-')
		return (FALSE);
	while (arg[i] == 'n')
		i++;
	if (i > 1 && arg[i] == '\0')
		return (TRUE);
	return (FALSE);
}

void	builtin_echo(char **args)
{	
	char	*str;
	int		i;

	i = 1;
	if (args && args[i])
	{
		while (is_n_option(args[i]))
			i++;
		str = ft_join_split(args + i, " ");
		printf("%s", str);
		free(str);
	}
	if (i == 1)
		printf("\n");
}
