/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 22:42:15 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/15 22:56:58 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include <stdlib.h>
# include "ft_types.h"
# include "printf.h"

int		cmp_int(void *a, void *b);
int		cmp_str(void *a, void *b);
void	lst_bubble_sort(t_list *head, int (*cmp)(void *, void *));
void	lst_add_back(t_list **lst, t_list *new);
void	lst_add_front(t_list **lst, t_list *new);
void	lst_clear(t_list **lst, void (*del)(void *));
void	lst_del_back(t_list **head, void (*del)(void *));
void	lst_del_front(t_list **head, void (*del)(void *));
void	lst_del_node(t_list *lst, void (*del)(void *));
void	lst_iter(t_list *lst, void (*f)(void *));
void	lst_print_int(t_list *head);
int		lst_size(t_list *lst);
t_list	*lst_last(t_list *lst);
t_list	*lst_map(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*lst_new(void *content);

#endif