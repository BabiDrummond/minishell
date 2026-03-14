/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:11:00 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 20:10:48 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast	*ast_new(void *value)
{
	t_ast	*ast;

	ast = ft_calloc(1, sizeof(t_ast));
	ast->left = NULL;
	ast->right = NULL;
	ast->value = value;
	return (ast);
}
