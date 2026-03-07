/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   should_collect_heredoc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:30:25 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/07 00:51:23 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

int	should_collect_heredoc(t_token *token)
{
	if (token->is_operator
		&& ft_strcmp(((char *)token->link.content), "<<") == 0)
		return (1);
	return (0);
}
