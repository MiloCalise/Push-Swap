/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:02:56 by miltavar          #+#    #+#             */
/*   Updated: 2025/06/23 13:35:03 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_lists **lst_a, t_lists **lst_b)
{
	int	i;

	i = rotate(lst_a);
	if (i < 0)
	{
		free_list(lst_a);
		free_list(lst_b);
		exit (1);
	}
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_lists **lst_b, t_lists **lst_a)
{
	int	i;

	i = rotate(lst_b);
	if (i < 0)
	{
		free_list(lst_a);
		free_list(lst_b);
		exit (1);
	}
	ft_putstr_fd("rb\n", 1);
}

void	sa(t_lists **lst_a)
{
	swap(lst_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_lists **lst_b)
{
	swap(lst_b);
	ft_putstr_fd("sb\n", 1);
}

void	rra(t_lists **lst_a)
{
	reverse_rotate(lst_a);
	ft_putstr_fd("rra\n", 1);
}
