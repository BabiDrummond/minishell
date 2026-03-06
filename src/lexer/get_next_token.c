/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:53:16 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/06 18:51:54 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	**get_not_quoted_word(char *str, char **operators)
{
	t_word	*word;
	char	*start;
	char	*end;
	int		len;

	start = str;
	end = start;
	while (*end && get_char_type(end, operators) == IS_NORMAL)
		end++;
	len = end - start;
	word = create_word(start, len, QUOTE_NONE);
	return (create_token_result(str + len, word));
}

void	**get_quoted_word(char *str, char **operators, t_char_type type)
{
	t_word	*word;
	char	*start;
	char	*end;
	int		len;

	start = str + (type == IS_SINGLE_QUOTE || type == IS_DOUBLE_QUOTE);
	end = start;
	while (*end && get_char_type(end, operators) != type)
		end++;
	if (get_char_type(end, operators) == IS_NULL)
		syntax_error();
	len = end - start;
	if (type == IS_SINGLE_QUOTE)
		word = create_word(start, len, QUOTE_SINGLE);
	else
		word = create_word(start, len, QUOTE_DOUBLE);
	return (create_token_result(str + len + 2, word));
}

void	**get_word_token(char *str, char **operators)
{
	t_char_type	type;
	t_head		*parts;
	void		**result;

	parts = lst_new_head();
	while (1)
	{
		type = get_char_type(str, operators);
		if (type == IS_NORMAL
			|| type == IS_SINGLE_QUOTE || type == IS_DOUBLE_QUOTE)
		{
			if (type == IS_NORMAL)
				result = get_not_quoted_word(str, operators);
			else
				result = get_quoted_word(str, operators, type);
			str = (char *)result[0];
			lst_add_last(parts, result[1]);
			continue ;
		}
		break ;
	}
	return (create_token_result(str, create_token(parts, 0)));
}

void	**get_operator_token(char *str, char **operators)
{
	int	i;

	i = 0;
	while (operators[i])
	{
		if (ft_strncmp(str, operators[i], ft_strlen(operators[i])) == 0)
			return (create_token_result(str + ft_strlen(operators[i]),
					create_token(operators[i], 1)));
		i++;
	}
	return (create_token_result(str, NULL));
}

void	**get_next_token(char *str, char **operators)
{
	t_char_type		char_type;

	char_type = get_char_type(str, operators);
	if (char_type == IS_NULL)
		return (create_token_result(NULL, NULL));
	if (char_type == IS_WHITESPACE)
		return (create_token_result(str + 1, NULL));
	if (char_type == IS_OPERATOR)
		return (get_operator_token(str, operators));
	return (get_word_token(str, operators));
}
