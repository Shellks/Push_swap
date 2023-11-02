/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:35:07 by acarlott          #+#    #+#             */
/*   Updated: 2023/03/09 13:29:10 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	index_count(t_swap *swap, int *temp)
{
	int	index;
	int	i;

	i = 0;
	index = 0;
	while (i < swap->size_a)
	{
		if (temp[swap->count] > temp[i])
			index++;
		i++;
	}
	swap->count++;
	return (index);
}

int	*ft_convert_index(t_swap *swap, int *temp)
{
	int	*heap_a;
	int	i;

	i = 0;
	heap_a = (int *)malloc(sizeof(int) * swap->size_a);
	if (!heap_a)
	{
		free (temp);
		exit (1);
	}
	swap->count = 0;
	while (i < swap->size_a)
	{
		heap_a[i] = index_count(swap, temp);
		i++;
	}
	free (temp);
	return (heap_a);
}

void	ft_write_exit(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_free(char **str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		free (str[x]);
		x++;
	}
	free (str);
	return ;
}

void	ft_check_string(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		if (ft_strlen(argv[i]) == 1 && (*argv[i] == '\0' || *argv[i] == ' '))
			ft_write_exit();
		if (ft_strlen(argv[i]) == 0)
			ft_write_exit();
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		ft_write_exit();
}
