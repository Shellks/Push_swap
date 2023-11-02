/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:46:01 by acarlott          #+#    #+#             */
/*   Updated: 2023/02/28 16:39:18 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_count_char(char **argv)
{
	int	x;
	int	y;
	int	size;

	x = 1;
	size = 0;
	while (argv[x])
	{
		y = 0;
		while (argv[x][y])
		{
			y++;
			size++;
		}
		size++;
		x++;
	}
	return (size);
}

char	**ft_convert_arg(t_swap *swap, char **argv)
{
	char	*s;
	char	**str;
	int		x;
	int		y;
	int		size;

	size = ft_count_char(argv);
	s = (char *)malloc(sizeof(char *) * size);
	if (!s)
		return (NULL);
	swap->i = 0;
	x = 1;
	while (argv[x])
	{
		y = 0;
		while (argv[x][y])
			s[swap->i++] = argv[x][y++];
		s[swap->i++] = ' ';
		x++;
	}
	s[swap->i] = '\0';
	str = ft_split(s, ' ');
	free (s);
	return (str);
}

static int	*ft_create_b(t_swap *swap)
{
	swap->size_b = 0;
	swap->heap_b = (int *)ft_calloc((swap->size_a), sizeof(int *));
	if (!swap->heap_b)
	{
		free(swap->heap_a);
		exit (1);
	}
	return (swap->heap_b);
}

static int	*ft_convert_long_to_int(t_swap *swap, long long int *old_heap)
{
	int	i;
	int	*new_heap;

	new_heap = (int *)malloc(sizeof(int *) * (swap->size_a));
	if (!new_heap)
	{
		free(old_heap);
		exit (1);
	}
	i = 0;
	while (i < swap->size_a)
	{
		if (old_heap[i] < INT_MIN || old_heap[i] > INT_MAX)
		{
			free(new_heap);
			free(old_heap);
			ft_write_exit();
		}
		new_heap[i] = (int)old_heap[i];
		i++;
	}
	free(old_heap);
	return (new_heap);
}

void	ft_parse(t_swap *swap)
{
	long long int	*long_temp;
	int				*temp;
	int				i;
	int				j;

	i = 0;
	j = -1;
	long_temp = malloc(sizeof(long long int *) * (swap->size_a));
	if (!long_temp)
	{
		ft_free(swap->str);
		exit (1);
	}
	while (i < swap->size_a)
		long_temp [++j] = ft_atoi(swap->str[i++]);
	ft_free(swap->str);
	temp = ft_convert_long_to_int(swap, long_temp);
	swap->heap_a = ft_convert_index(swap, temp);
	ft_create_b(swap);
	i = 0;
	j = 0;
	return ;
}
