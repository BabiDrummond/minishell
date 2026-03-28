/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_content_heredoc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:58:27 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 20:21:12 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

char	**split_content_heredoc(t_word *words)
{
	char	**argv;
	int		size;
	int		i;

	i = 0;
	size = lst_size((t_list *) words);
	argv = ft_calloc(size + 1, sizeof(char *));
	while (words && i < size)
	{
		argv[i] = (char *)words->link.content;
		i++;
		words = (t_word *) words->link.next;
	}
	return (argv);
}
