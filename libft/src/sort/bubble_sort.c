/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 21:31:08 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/15 22:49:10 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;
	int	swapped;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		swapped = 0;
		while (++j < size - 1)
		{
			if (arr[j] > arr [j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
		}
		if (!swapped)
			break ;
	}
	return (arr);
}
// int main(void)
// {
// 	int tab[5] = {9, 3, 1, 2, 4};
// 	int size = 5;
// 	int i = 0;
// 	int *res = malloc(5 * sizeof(int));
// 	res = bubble_sort(tab, size);
// 	while (i < size)       
// 		printf("%d", res[i++]);
// }
