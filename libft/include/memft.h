/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 00:01:18 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 12:46:41 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMFT_H
# define MEMFT_H
# include <stddef.h>
# include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t type_size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_malloc(size_t size);

#endif