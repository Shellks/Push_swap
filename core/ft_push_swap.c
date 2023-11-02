/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:42:48 by acarlott          #+#    #+#             */
/*   Updated: 2023/02/28 15:44:58 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_swap *swap)
{
	int	i;

	i = 0;
	while (i < swap->size_a - 1)
	{
		if (swap->heap_a[i] > swap->heap_a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

static void	three_sort(t_swap *swap)
{
	int	*heap;

	heap = swap->heap_a;
	if (heap[0] > heap[1] && heap[1] < heap[2] && heap[0] > heap[2])
		rotate_a(swap);
	else if (heap[0] > heap[1] && heap[1] < heap[2] && heap[0] < heap[2])
		swap_a(swap);
	else if (heap[0] < heap[1] && heap[1] > heap[2] && heap[0] > heap[2])
		reverse_rotate_a(swap);
	else if (heap[0] < heap[1] && heap[1] > heap[2] && heap[0] < heap[2])
	{
		reverse_rotate_a(swap);
		swap_a(swap);
	}
	else if (heap[0] > heap[1] && heap[1] > heap[2] && heap[0] > heap[2])
	{
		swap_a(swap);
		reverse_rotate_a(swap);
	}
}

static void	five_sort(t_swap *swap)
{
	push_min(swap);
	push_min(swap);
	three_sort(swap);
	push_a(swap);
	push_a(swap);
}

static void	radix_sort(t_swap *swap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (is_sorted(swap) == 1)
	{
		while (i < (swap->size_a + swap->size_b))
		{
			if (swap->heap_a[0] >> j & 1)
				rotate_a(swap);
			else
				push_b(swap);
			i++;
		}
		while (i > 0)
		{
			push_a(swap);
			i--;
		}
		j++;
	}
}

int	ft_push_swap(t_swap *swap)
{
	if (swap->size_a == 2 && is_sorted(swap) == 1)
		swap_a(swap);
	else if (swap->size_a == 3 && is_sorted(swap) == 1)
		three_sort(swap);
	else if (swap->size_a == 5 && is_sorted(swap) == 1)
		five_sort(swap);
	else if (is_sorted(swap) == 1)
		radix_sort(swap);
	return (0);
}
