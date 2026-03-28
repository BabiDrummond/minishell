/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:40:23 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/28 01:26:18 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

# include "list.h"

typedef enum e_gc_scope
{
	GC_SCOPE_GLOBAL,
	GC_SCOPE_FUNCTION,
	GC_SCOPE_COUNT
}	t_gc_scope;

typedef struct s_gc_node
{
	t_node	link;
	void	(*destructor)(void *);
}	t_gc_node;

t_gc_node	*create_gc_node(void *ptr, void (*destructor)(void *));
t_head		*get_collector(void);
void		gc_node_free(t_gc_node *gc_node);
void		gc_add(void *ptr, void (*destructor)(void *));
void		gc_free_all(void);
void		gc_exit(int exit_status);
void		gc_add_or_exit(void *ptr, void (*destructor)(void *));
void		gc_set_current_scope(t_gc_scope new_scope);
t_gc_scope	*gc_get_current_scope(void);

#endif