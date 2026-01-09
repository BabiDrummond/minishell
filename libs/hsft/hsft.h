/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsft.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 00:01:18 by bcosta-b          #+#    #+#             */
/*   Updated: 2025/12/09 12:35:14 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSFT_H
# define HSFT_H
# include <stddef.h>
# include "listft.h"

typedef struct s_hsnode
{
	void			*key;
	struct s_hsnode	*next;
}	t_hsnode;

typedef struct s_hashset
{
	struct s_hsnode	**buckets;
	size_t			size;
	size_t			count;
	size_t			(*hash_func)(void *, size_t);
	int				(*compare_func)(void*, void*);
	void			(*free_func)(struct s_hashset*, void (*free_key)(void*));
	void			(*free_key)(void*);
}	t_hashset;

void		hs_free(t_hashset *hs, void (*free_key)(void*));
void		hs_resize(t_hashset *hs);
void		hs_add(t_hashset *hs, void *key);

size_t		hash_int_knuth(void *key, size_t size);

t_hsnode	*hsnode_new(void *key);

t_hashset	*hs_new(size_t size,
				size_t (*hash_func)(void*, size_t),
				int (*compare_func)(void*, void*),
				void (*free_key)(void*));

t_hashset	*hs_from_lst(t_list *lst,
				size_t (*hash_func)(void*, size_t),
				int (*compare_func)(void*, void*),
				void (*free_key)(void*));

#endif