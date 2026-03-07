/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:libft/src/str/ft_substr.c
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:13:20 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/23 01:17:27 by bmoreira         ###   ########.fr       */
========
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 06:46:05 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/18 17:24:20 by bmoreira         ###   ########.fr       */
>>>>>>>> builtins:libft/src/str/ft_strdup.c
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

<<<<<<<< HEAD:libft/src/str/ft_substr.c
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	ft_memcpy(substr, (s + start), len);
	return (substr);
========
char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	new = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (s[++i])
		new[i] = s[i];
	return (new);
>>>>>>>> builtins:libft/src/str/ft_strdup.c
}
