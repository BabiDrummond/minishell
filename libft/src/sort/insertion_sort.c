/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 22:03:32 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/15 22:49:18 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*insertion_sort(int *arr, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j > 0 && arr[j] < arr[j - 1])
		{
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
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
// 	res = insertion_sort(tab, size);
// 	while (i < size)       
// 		printf("%d", res[i++]);
// }