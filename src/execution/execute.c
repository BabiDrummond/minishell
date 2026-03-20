/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 03:51:40 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/19 22:33:01 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// int	print_error_and_return(t_shell *ctx, char *error_msg, int exit_status)
// {
// 	perror(error_msg);
// 	ctx->exit_status = exit_status;
// 	return (ctx->exit_status);
// }

int	execute(t_shell *ctx, t_ast *ast, int is_child)
{
	t_exec_node	*node;

	if (!ast)
		return (EXIT_SUCCESS);
	node = (t_exec_node *) ast->value;
	if (node->type == NODE_CMD)
		return (execute_cmd(ctx, node, is_child));
	return (execute_operator(ctx, ast, node, is_child));
}
