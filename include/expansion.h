/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbara.drummond <barbara.drummond@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 20:55:14 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/21 17:42:29 by barbara.dru      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "lexer.h"
# include "../libft/include/libft.h"

# define QUOTE_GUARD '\x01'

char	**split_unquoted(char *s, char c);

#endif