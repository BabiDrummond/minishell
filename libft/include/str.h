/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 22:42:31 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/27 03:47:51 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <unistd.h>
# include <stdlib.h>
# include "mem.h"
# include "types.h"

char	*append_char(char *str, char c);
char	*ft_itoa(int n);
char	*ft_join_split(char **split, char *separator);
int		ft_split_size(char **split);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_triple_join(char *s1, char *s2, char *s3);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strndup(const char *s, size_t n);
size_t	ft_strlen(const char *s);
char	**merge_splits(char **first, char **second);

#endif