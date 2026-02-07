/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 00:01:18 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/02/07 18:44:10 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGFT_H
# define STRINGFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "memft.h"
# include "charft.h"

typedef struct s_string
{
	char	*value;
	size_t	length;
}	t_string;

t_string	*str_new(size_t len);
t_string	*str_new_char(char c);
t_string	*str_new_values(char *value, size_t len);
t_string	*str_dup(const char *s);
size_t		ft_strlen(const char *s);
size_t		ft_putstr(char *str);
size_t		put_string(t_string *str);
void		str_free(void *str);
void		free_split(char **split);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(const char *s1, const char *s2);
char		**ft_split(const char *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_is_number(char *str);

#endif