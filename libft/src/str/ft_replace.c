/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 01:53:03 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/28 03:12:26 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

static char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] && needle[j]
			&& haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

static int	count_occurrences(const char *str, const char *sub)
{
	int	count;
	size_t	len;

	count = 0;
	len = ft_strlen(sub);
	while ((str = ft_strstr(str, sub)))
	{
		count++;
		str += len;
	}
	return (count);
}

static void	fill_replace(char *result, const char *str,
	const char *placeholder, const char *value)
{
	char	*tmp;
	size_t	len_ph;
	size_t	len_val;

	tmp = result;
	len_ph = ft_strlen(placeholder);
	len_val = ft_strlen(value);
	while (*str)
	{
		if (ft_strstr(str, placeholder) == str)
		{
			ft_memcpy(tmp, value, len_val);
			tmp += len_val;
			str += len_ph;
		}
		else
			*tmp++ = *str++;
	}
	*tmp = '\0';
}

char	*ft_replace(const char *str, const char *placeholder, const char *value)
{
	char	*result;
	size_t	len_result;
	size_t	len_ph;
	size_t	len_val;
	int		count;

	if (!str || !placeholder || !value)
		return (NULL);
	len_ph = ft_strlen(placeholder);
	len_val = ft_strlen(value);
	count = count_occurrences(str, placeholder);
	if (count == 0)
		return (ft_strdup(str));
	len_result = ft_strlen(str) + (len_val - len_ph) * count;
	result = ft_calloc(len_result + 1, sizeof(char));
	fill_replace(result, str, placeholder, value);
	return (result);
}
