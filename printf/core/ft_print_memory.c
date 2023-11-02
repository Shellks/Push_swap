/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:28:09 by acarlott          #+#    #+#             */
/*   Updated: 2023/01/30 17:17:06 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	ft_print_memory(unsigned long nbr)
{
	unsigned long int	nb;
	int					count;
	char				*base;

	nb = nbr;
	count = 0;
	base = "0123456789abcdef";
	if (nb > 15)
		count += ft_print_memory(nb / 16);
	count += ft_printchar(base[nb % 16]);
	return (count);
}
