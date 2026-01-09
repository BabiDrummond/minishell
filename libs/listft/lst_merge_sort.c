/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_merge_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 22:50:27 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 12:47:02 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listft.h"
#include "memft.h"

static void	split(t_list *lst, t_list *a, t_list *b)
{
	t_node	*middle;
	t_node	*ptr;

	ptr = lst->first;
	middle = lst->first;
	while (ptr && ptr->next && ptr->next->next)
	{
		middle = middle->next;
		ptr = ptr->next->next;
	}
	a->first = lst->first;
	a->last = middle;
	b->first = middle->next;
	b->last = lst->last;
	a->last->next = NULL;
	b->first->prev = NULL;
	a->count = (lst->count / 2 + lst->count % 2);
	b->count = lst->count - a->count;
	lst->first = NULL;
	lst->last = NULL;
	lst->count = 0;
}

static void	merge(t_list *lst,
	t_list *a,
	t_list *b,
	int (*compare)(void*, void*)
)
{
	while (a->first || b->first)
	{
		if (a->first && b->first)
		{
			if (compare(a->first->content, b->first->content) <= 0)
				lst_add_last(lst, lst_pop(a));
			else
				lst_add_last(lst, lst_pop(b));
		}
		else if (!a->first)
		{
			lst_add_last(lst, lst_pop(b));
		}
		else
		{
			lst_add_last(lst, lst_pop(a));
		}
	}
	lst->count = a->count + b->count;
}

void	lst_merge_sort(t_list *lst, int (*compare)(void*, void*))
{
	t_list	a;
	t_list	b;

	if (!lst->first || !lst->first->next)
		return ;
	ft_memset(&a, 0, sizeof(t_list));
	ft_memset(&b, 0, sizeof(t_list));
	split(lst, &a, &b);
	lst_merge_sort(&a, compare);
	lst_merge_sort(&b, compare);
	merge(lst, &a, &b, compare);
}
