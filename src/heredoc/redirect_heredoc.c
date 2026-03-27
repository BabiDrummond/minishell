/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:22:35 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 20:25:23 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

int	redirect_heredoc(char **target)
{
	char	*string;
	int		pipefd[2];

	string = ft_join_split(target, "\n");
	pipe(pipefd);
	write(pipefd[1], string, ft_strlen(string));
	write(pipefd[1], "\n", 1);
	close(pipefd[1]);
	return (pipefd[0]);
}
