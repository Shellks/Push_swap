/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:15:58 by acarlott          #+#    #+#             */
/*   Updated: 2023/02/28 15:42:16 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_ab(t_swap *swap)
{
	int	temp_a;
	int	temp_b;

	if (swap->size_a > 1 && swap->size_b > 1)
	{
		temp_a = swap->heap_a[0];
		swap->heap_a[0] = swap->heap_a[1];
		swap->heap_a[1] = temp_a;
		temp_b = swap->heap_b[0];
		swap->heap_b[0] = swap->heap_b[1];
		swap->heap_b[1] = temp_b;
		ft_printf("ss\n");
	}
	return ;
}

void	swap_b(t_swap *swap)
{
	int	temp;

	if (swap->size_b > 1)
	{
		temp = swap->heap_b[0];
		swap->heap_b[0] = swap->heap_b[1];
		swap->heap_b[1] = temp;
		ft_printf("sb\n");
	}
	return ;
}

void	swap_a(t_swap *swap)
{
	int	temp;

	if (swap->size_a > 1)
	{
		temp = swap->heap_a[0];
		swap->heap_a[0] = swap->heap_a[1];
		swap->heap_a[1] = temp;
		ft_printf("sa\n");
	}
	return ;
}
