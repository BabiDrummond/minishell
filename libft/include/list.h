/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 00:01:18 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/07 00:50:23 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "mem.h"

typedef struct s_head
{
	struct s_node	*first;
	struct s_node	*last;
	size_t			count;
}	t_head;

typedef struct s_node
{
	void			*content;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_head	*list;
}	t_node;

t_node	*lst_add_last(t_head *lst, t_node *node);
t_node	*lst_detach(t_head *lst, t_node *node);
t_node	*lst_pop(t_head *lst);
t_head	*lst_new_head(void);

#endif