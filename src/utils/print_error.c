/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 02:07:22 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/28 03:47:58 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_error(char *error_message, int error_code)
{
	t_shell	*ctx;

	ctx = get_shell_ctx();
	ctx->exit_status = error_code;
	ft_putstr_fd(error_message, 2);
	return (error_code);
}


int	print_syntax_error(char *token)
{
	return (print_error(ft_replace("bash: syntax error near unexpected token `%s'\n", "%s", token), SYNTAX_ERROR));
}
