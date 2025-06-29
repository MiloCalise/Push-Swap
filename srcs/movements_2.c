/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:12:47 by miltavar          #+#    #+#             */
/*   Updated: 2025/06/23 13:29:43 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrb(t_lists **lst_b)
{
	reverse_rotate(lst_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_lists **lst_a, t_lists **lst_b)
{
	reverse_rotate(lst_a);
	reverse_rotate(lst_b);
	ft_putstr_fd("rrr\n", 1);
}

void	ss(t_lists **lst_a, t_lists **lst_b)
{
	swap(lst_a);
	swap(lst_b);
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_lists **lst_a, t_lists **lst_b)
{
	int	i;

	i = rotate(lst_a);
	if (i < 0)
	{
		free_list(lst_a);
		free_list(lst_b);
		exit (1);
	}
	i = rotate(lst_b);
	if (i < 0)
	{
		free_list(lst_a);
		free_list(lst_b);
		exit (1);
	}
	ft_putstr_fd("rr\n", 1);
}

int	find_pos(t_lists *lst, int value)
{
	int	pos;

	pos = 0;
	while (lst)
	{
		if (lst->content == value)
			return (pos);
		lst = lst->next;
		pos++;
	}
	return (-1);
}
