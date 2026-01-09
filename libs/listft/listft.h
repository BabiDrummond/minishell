/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 00:01:18 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 18:47:23 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTFT_H
# define LISTFT_H
# include <stddef.h>

typedef struct s_list
{
	struct s_node	*first;
	struct s_node	*last;
	size_t			count;
}	t_list;

typedef struct s_node
{
	void			*content;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_list	*list;
}	t_node;

t_node	*lst_detach(t_list *lst, t_node *node);
t_node	*lst_push(t_list *lst, t_node *node);
t_node	*lst_pop(t_list *lst);
t_node	*lst_new_node(void *content);
t_node	*lst_add_after(t_node *target, t_node *node);
t_node	*lst_add_before(t_node *target, t_node *node);
t_node	*lst_add_first(t_list *lst, t_node *node);
t_node	*lst_add_last(t_list *lst, t_node *node);
void	lst_merge_sort(t_list *lst, int (*compare)(void*, void*));
void	lst_delete_all(t_list *lst, void (*free_content)(void*));
void	lst_delete_node(t_node *node, void (*free_content)(void*));
void	lst_delete(t_list *lst, void (*free_content)(void*));
void	lst_foreach(t_list *lst, void (*f)(t_node *));
size_t	lst_sum(t_list *lst, size_t(*f)(t_node*));
int		lst_is_detached(const t_node *node);
int		lst_is_equal(const t_node *target, const t_node *node);
int		lst_is_first(t_node *node);
int		lst_is_invalid(const t_node *node);
int		lst_is_last(t_node *node);
void	lst_dup(t_list *src, t_list *dest, void *(*dup)(void *));

#endif