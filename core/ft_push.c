/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:44:11 by acarlott          #+#    #+#             */
/*   Updated: 2023/02/28 15:42:52 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_min(t_swap *swap)
{
	int	i;
	int	min_index;
	int	min_value;

	i = 0;
	min_index = 0;
	min_value = swap->heap_a[0];
	while (i < swap->size_a)
	{
		if (swap->heap_a[i] < min_value)
		{
			min_value = swap->heap_a[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	push_min(t_swap *swap)
{
	int	index;

	index = get_min(swap);
	if (index == 0)
	{
		push_b(swap);
		return ;
	}
	else if (index == 1)
		swap_a(swap);
	else if (index == 2)
	{
		rotate_a(swap);
		swap_a(swap);
	}
	else if (index == 3)
	{
		rotate_a(swap);
		rotate_a(swap);
		rotate_a(swap);
	}
	else if (index == 4)
		reverse_rotate_a(swap);
	push_b(swap);
	return ;
}

void	push_a(t_swap *swap)
{
	int	i;

	if (swap->size_b == 0)
		return ;
	swap->size_a++;
	i = swap->size_a - 1;
	while (i > 0)
	{
		swap->heap_a[i] = swap->heap_a[i - 1];
		i--;
	}
	swap->heap_a[0] = swap->heap_b[0];
	swap->size_b--;
	i = 0;
	while (i < swap->size_b)
	{
		swap->heap_b[i] = swap->heap_b[i + 1];
		i++;
	}
	ft_printf("pa\n");
}

void	push_b(t_swap *swap)
{
	int	i;

	if (swap->size_a == 0)
		return ;
	swap->size_b++;
	i = (swap->size_b - 1);
	while (i > 0)
	{
		swap->heap_b[i] = swap->heap_b[i - 1];
		i--;
	}
	swap->heap_b[0] = swap->heap_a[0];
	swap->size_a--;
	i = 0;
	while (i < swap->size_a)
	{
		swap->heap_a[i] = swap->heap_a[i + 1];
		i++;
	}
	ft_printf("pb\n");
}
