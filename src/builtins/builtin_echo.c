/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:42:57 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/28 22:01:59 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int			builtin_echo(char **argv);
static int	is_n_option(char *arg);

int	builtin_echo(char **argv)
{
	char	*str;
	int		i;

	i = 1;
	if (argv && argv[i])
	{
		while (is_n_option(argv[i]))
			i++;
		str = ft_join_split(argv + i, " ");
		printf("%s", str);
	}
	if (i == 1)
		printf("\n");
	return (EXIT_SUCCESS);
}

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
