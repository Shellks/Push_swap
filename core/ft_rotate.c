/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:10:56 by acarlott          #+#    #+#             */
/*   Updated: 2023/02/28 15:45:17 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_a(t_swap *swap)
{
	int	temp;
	int	size;

	size = (swap->size_a - 1);
	temp = swap->heap_a[size];
	while (size > 0)
	{
		swap->heap_a[size] = swap->heap_a[size - 1];
		size--;
	}
	swap->heap_a[size] = temp;
	ft_printf("rra\n");
}

void	rotate_a(t_swap *swap)
{
	int	temp;
	int	size;
	int	i;

	i = 0;
	size = (swap->size_a - 1);
	temp = swap->heap_a[0];
	while (i < size)
	{
		swap->heap_a[i] = swap->heap_a[i + 1];
		i++;
	}
	swap->heap_a[size] = temp;
	ft_printf("ra\n");
}
