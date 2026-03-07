/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
<<<<<<<< HEAD:libft/src/str/ft_strdup.c
=======
<<<<<<<< HEAD:libft/src/str/ft_substr.c
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:13:20 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/23 01:17:27 by bmoreira         ###   ########.fr       */
========
>>>>>>> builtins
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 06:46:05 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/18 17:24:20 by bmoreira         ###   ########.fr       */
<<<<<<< HEAD
=======
>>>>>>>> builtins:libft/src/str/ft_strdup.c
>>>>>>> builtins
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

<<<<<<< HEAD
=======
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
>>>>>>> builtins
char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	i = -1;
<<<<<<< HEAD
=======
	if (!s)
		return (NULL);
>>>>>>> builtins
	new = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (s[++i])
		new[i] = s[i];
	return (new);
<<<<<<< HEAD
========
/*   var_extract_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:02:36 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 20:03:39 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_value(char *var_content)
{
	char	*equal;

	equal = ft_strchr(var_content, '=');
	if (equal)
		return (ft_strdup(equal + 1));
	return (NULL);
>>>>>>>> builtins:src/utils/extract_value.c
=======
>>>>>>>> builtins:libft/src/str/ft_strdup.c
>>>>>>> builtins
}
