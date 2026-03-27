/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 22:42:15 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 01:55:58 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include <stdlib.h>
# include "types.h"
# include "mem.h"

void	lst_add_back(t_list **lst, t_list *new);
void	lst_clear_node(t_list *lst, void (*del)(void *));
void	lst_clear(t_list **lst, void (*del)(void *));
void	lst_del_node(t_list **head, t_list *node, void (*del)(void *));
int		lst_size(t_list *lst);
t_list	*lst_last(t_list *lst);
t_list	*lst_new(void *content);

#endif