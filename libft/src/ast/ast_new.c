/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:11:00 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/27 02:33:20 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast	*ast_new(void *value)
{
	t_ast	*ast;

	ast = safe_calloc(1, sizeof(t_ast));
	ast->left = NULL;
	ast->right = NULL;
	ast->value = value;
	return (ast);
}
