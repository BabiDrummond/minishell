/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_bubble_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 00:48:10 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/18 17:21:37 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

int	cmp_int(void *a, void *b)
{
	return (*(int *)a > *(int *)b);
}

int	cmp_str(void *a, void *b)
{
	return (ft_strncmp((char *)a, (char *)b, ft_strlen((char *)a)) > 0);
}

void	lst_bubble_sort(t_list *head, int (*cmp)(void *, void *))
{
	t_list	*curr;
	void	*temp;
	int		size;
	int		swapped;

	if (!head)
		return ;
	size = lst_size(head);
	while (size--)
	{
		curr = head;
		swapped = 0;
		while (curr->next)
		{
			if (cmp(curr->content, curr->next->content) && ++swapped)
			{
				temp = curr->content;
				curr->content = curr->next->content;
				curr->next->content = temp;
			}
			curr = curr->next;
		}
		if (!swapped)
			break ;
	}
}

// void	print_list_int(t_list *head)
// {
// 	while(head)
// 	{
// 		printf("%d", *(int *)head->content);
// 		head = head->next;
// 	}
// 	printf("\n");
// }

// void	print_list_str(t_list *head)
// {
// 	while(head)
// 	{
// 		printf("%s", (char *)head->content);
// 		head = head->next;
// 	}
// 	printf("\n");
// }

// int main(void)
// {
//  // Test with ints
// 	t_list *head = NULL;
// 	int vals[] = {9, 3, 1, 2, 4};
// 	int i = 0;

// 	while (i < 5)
// 		lst_add_back(&head, lst_new(&vals[i++]));

// 	printf("Before: ");
// 	print_list_int(head);
// 	lst_bubble_sort(head, cmp_int);
// 	printf("After: ");
// 	print_list_int(head);

//  // Test with strings
//  t_list *head2 = NULL;
//  char *vals2[] = {"c", "b", "a", "e", "f"};
//  int j = 0;

// 	while (j < 5)
// 		lst_add_back(&head2, lst_new(vals2[j++]));

//  printf("Before: ");
// 	print_list_str(head2);

// 	lst_bubble_sort(head2, cmp_str);

//     printf("After: ");
// 	print_list_str(head2);
// }