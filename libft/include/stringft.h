/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 00:01:18 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 20:22:38 by bcosta-b         ###   ########.fr       */
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
char		*ft_strchr(const char *s, int c);
size_t		put_string(t_string *str);
void		str_free(void *str);
void		free_split(char **split);
char		**ft_split(char *s);
int			ft_is_number(char *str);
char		*ft_strndup(const char *s, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);

#endif