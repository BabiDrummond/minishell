/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 04:07:43 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/18 17:22:35 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (n-- && (*(unsigned char *)s1++ == *(unsigned char *)s2++))
		;
	return (*(unsigned char *)--s1 - *(unsigned char *)--s2);
}

/*
int main( void )
{
	#include <string.h>
	#include <stdio.h>
	char first[]  = "12345678901234567892";
	char second[] = "12345678901234567891";
	int int_arr1[] = {1,2,3,4};
	int int_arr2[] = {1,2,3,4};
	int result;

	printf( "Compare '%.19s' to '%.19s':\n", first, second );
	result = ft_memcmp( first, second, 19 );
	if( result < 0 )
		printf( "First is less than second.\n" );
	else if( result == 0 )
		printf( "First is equal to second.\n" );
	else
		printf( "First is greater than second.\n" );

	result = ft_memcmp( int_arr1, int_arr2, sizeof(int) * 2 );
	if( result < 0 )
		printf( "int_arr1 is less than int_arr2.\n" );
	else if( result == 0 )
		printf( "int_arr1 is equal to int_arr2.\n" );
	else
		printf( "int_arr1 is greater than int_arr2.\n" );
}
*/