/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:29:31 by acarlott          #+#    #+#             */
/*   Updated: 2023/03/09 13:25:45 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_swap	swap;

	swap.size_a = 0;
	ft_error(&swap, argc, argv);
	ft_parse(&swap);
	ft_error2(&swap);
	ft_push_swap(&swap);
	free (swap.heap_a);
	free (swap.heap_b);
	return (0);
}
