/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:29:59 by acarlott          #+#    #+#             */
/*   Updated: 2023/03/09 13:45:45 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../printf/include/printf.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_swap
{
	char	**str;
	int		*heap_a;
	int		*heap_b;
	int		size_a;
	int		size_b;
	int		count;
	int		i;
}	t_swap;

void	swap_ab(t_swap *swap);
void	ft_free(char **str);
void	ft_write_exit(void);
void	swap_a(t_swap *swap);
void	swap_b(t_swap *swap);
void	push_a(t_swap *swap);
void	push_b(t_swap *swap);
void	push_min(t_swap *swap);
void	rotate_a(t_swap *swap);
void	ft_parse(t_swap *swap);
void	ft_error2(t_swap *swap);
int		ft_push_swap(t_swap *swap);
int		main(int argc, char **argv);
void	reverse_rotate_a(t_swap *swap);
void	ft_check_string(int argc, char **argv);
int		*ft_convert_index(t_swap *swap, int *temp);
char	**ft_convert_arg(t_swap *swap, char **argv);
void	ft_error(t_swap *swap, int argc, char **argv);

#endif
