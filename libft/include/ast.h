/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:14:43 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 20:24:36 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "mem.h"

typedef struct s_ast
{
	struct s_ast	*left;
	struct s_ast	*right;
	void			*value;
}	t_ast;

t_ast	*ast_new(void *value);

#endif
