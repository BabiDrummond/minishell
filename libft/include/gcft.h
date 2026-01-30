/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcft.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:40:23 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 19:22:01 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GCFT_H
# define GCFT_H

# include "listft.h"

typedef struct s_gc_node
{
	t_node	link;
	void	(*destructor)(void *);
}	t_gc_node;

t_gc_node	*create_gc_node(void *ptr, void (*destructor)(void *));
t_list		*get_collector(void);
void		gc_node_free(t_gc_node *gc_node);
void		gc_add(void *ptr, void (*destructor)(void *));
void		gc_free_all(void);
void		gc_exit(void);
void		gc_add_or_exit(void *ptr, void (*destructor)(void *));

#endif