/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:38:30 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/29 20:56:31 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tokens(t_head *tokens)
{
	t_token	*token;

	token = (t_token *)tokens->first;
	while (token)
	{
		print_token(token);
		token = (t_token *)token->link.next;
	}
}
