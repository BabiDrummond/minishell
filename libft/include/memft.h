/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 00:01:18 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/02/07 18:44:47 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMFT_H
# define MEMFT_H

# include <stddef.h>
# include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t type_size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

#endif