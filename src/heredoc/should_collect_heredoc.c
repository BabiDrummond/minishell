/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   should_collect_heredoc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:30:25 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/02/04 17:49:46 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	should_collect_heredoc(t_token *token)
{
	if (token->is_operator
		&& ft_strcmp(((char *)token->link.content), "<<") == 0)
		return (1);
	return (0);
}
