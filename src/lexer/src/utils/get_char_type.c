/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:49:35 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 18:35:49 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_private.h"

t_char_type	get_char_type(const char *str, char **operators)
{
	int	i;

	i = 0;
	if (!str || *str == '\0')
		return (IS_NULL);
	while (operators && operators[i])
	{
		if (ft_strncmp(str, operators[i], ft_strlen(operators[i])) == 0)
			return (IS_OPERATOR);
		i++;
	}
	if (*str == '\'')
		return (IS_SINGLE_QUOTE);
	if (*str == '"')
		return (IS_DOUBLE_QUOTE);
	if (ft_isspace(*str))
		return (IS_WHITESPACE);
	return (IS_NORMAL);
}
