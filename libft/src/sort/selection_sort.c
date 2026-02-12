/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 21:56:37 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/15 22:49:28 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*selection_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	min_index;
	int	temp;

	i = 0;
	while (i < size)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min_index])
				min_index = j;
			j++;
		}
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
		i++;
	}
	return (arr);
}

// int main(void)
// {
// 	int tab[5] = {9, 3, 1, 2, 4};
// 	int size = 5;
// 	int i = 0;
// 	int *res = malloc(5 * sizeof(int));
// 	res = selection_sort(tab, size);
// 	while (i < size)       
// 		printf("%d", res[i++]);
// }