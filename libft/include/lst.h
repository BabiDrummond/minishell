/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 22:42:15 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/22 04:08:23 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include <stdlib.h>
# include "types.h"

void	lst_add_back(t_list **lst, t_list *new);
int		lst_size(t_list *lst);
t_list	*lst_last(t_list *lst);
t_list	*lst_new(void *content);

#endif