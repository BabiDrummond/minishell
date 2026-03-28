/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_syntax_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:33:39 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/28 03:46:17 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "minishell.h"

static int	is_ast_operator(t_token *token)
{
	char	*operator;

	if (token->is_operator)
	{
		operator = token->link.content;
		if (ft_strcmp(operator, "&&") == 0
			|| ft_strcmp(operator, "||") == 0
			|| ft_strcmp(operator, "|") == 0)
			return (TRUE);
	}
	return (FALSE);
}

int	has_syntax_error(t_head *tokens)
{
	t_token	*current_token;

	current_token = (t_token *)tokens->first;
	if (is_ast_operator(current_token))
		return (print_error(ft_replace("bash: syntax error near unexpected token `%s'\n", "%s", current_token->link.content), SYNTAX_ERROR));
	while (current_token)
	{
		if (is_ast_operator(current_token) && (current_token->link.next == NULL
				|| is_ast_operator(((t_token *)current_token->link.next))))
			return (print_error(ft_replace("bash: syntax error near unexpected token `%s'\n", "%s", current_token->link.content), SYNTAX_ERROR));
		current_token = (t_token *)current_token->link.next;
	}
	return (FALSE);
}
