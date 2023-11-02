/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:21:10 by acarlott          #+#    #+#             */
/*   Updated: 2023/03/09 13:30:09 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_isvalid_nb(char c)
{
	char	*str;
	int		i;

	str = "0123456789";
	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_numb(char **arg)
{
	char	*str;
	int		i;
	int		x;
	int		y;

	str = "-+0123456789";
	i = 0;
	x = 0;
	while (arg[x])
	{
		y = -1;
		while (arg[x][++y])
		{
			while (str[i] && str[i] != arg[x][y])
				i++;
			if ((size_t)i == ft_strlen(str) || \
			((arg[x][0] == '-' && ft_strlen(arg[x]) == 1)) || \
			(arg[x][0] == '+' && ft_strlen(arg[x]) == 1) || \
			(y != 0 && ft_isvalid_nb(arg[x][y]) == 1))
				return (1);
			i = 0;
		}
		x++;
	}
	return (0);
}

static int	ft_check_duplicate(int *heap, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = (i + 1);
		while (j < size)
		{
			if (heap[i] == heap[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_error2(t_swap *swap)
{
	if (ft_check_duplicate(swap->heap_a, swap->size_a) == 1)
	{
		free(swap->heap_a);
		free(swap->heap_b);
		ft_write_exit();
	}
}

void	ft_error(t_swap *swap, int argc, char **argv)
{
	int	x;

	x = 1;
	if (argc <= 1)
		exit (0);
	ft_check_string(argc, argv);
	if (argc == 2)
		swap->str = ft_split(argv[1], ' ');
	else if (argc > 2)
		swap->str = ft_convert_arg(swap, argv);
	if (ft_check_numb(swap->str) == 1)
	{
		ft_free(swap->str);
		ft_write_exit();
	}
	x = 0;
	while (swap->str[x++])
		swap->size_a++;
}
