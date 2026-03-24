/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 20:04:04 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/24 01:12:39 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "execution.h"

char	**build_argv(t_list	*args)
{
	char	**argv;

	argv = NULL;
	if (!args)
		return (NULL);
	while (args)
	{
		argv = merge_splits(argv,
				split_unquoted((t_word *)((t_head *)args->content)->first));
		args = args->next;
	}
	return (argv);
}
