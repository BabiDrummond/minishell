/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_syntax_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:33:39 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/13 19:56:20 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_error(void)
{
	printf("Syntax Error: two consecutive operators\n");
	gc_exit();
	return (1);
}

static int	operator_is_redir(char *operator)
{
	return (ft_strcmp(operator, ">>") == 0
		|| ft_strcmp(operator, ">") == 0
		|| ft_strcmp(operator, "<") == 0);
}

int	has_syntax_error(t_head *tokens)
{
	t_token	*current_token;

	if (tokens == NULL)
		return (print_error());
	current_token = (t_token *)tokens->first;
	if (current_token->is_operator
		&& !operator_is_redir(current_token->link.content))
		return (print_error());
	while (current_token)
	{
		if (current_token->is_operator
			&& (current_token->link.next == NULL
				|| (((t_token *)current_token->link.next)->is_operator
				&& !operator_is_redir(current_token->link.next->content))))
			return (print_error());
		current_token = (t_token *)current_token->link.next;
	}
	return (0);
}
