/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:15:54 by miltavar          #+#    #+#             */
/*   Updated: 2025/06/11 15:56:32 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	two(t_lists **lst_a)
{
	if ((*lst_a)->content < (*lst_a)->next->content)
		sa(lst_a);
}

void	three(t_lists **lst_a)
{
	int	one;
	int	two;
	int	three;

	one = (*lst_a)->content;
	two = (*lst_a)->next->content;
	three = (*lst_a)->next->next->content;
	if (one > two && two < three && one < three)
		sa(lst_a);
	else if (one > two && two > three)
	{
		sa(lst_a);
		rra(lst_a);
	}
	else if (one > two && two < three && one > three)
		ra(lst_a);
	else if (one < two && two > three && one < three)
	{
		sa(lst_a);
		ra(lst_a);
	}
	else if (one < two && two > three && one > three)
		rra(lst_a);
}

void	four(t_lists **lst_a, t_lists **lst_b)
{
	int	pos;

	pos = get_min_pos(*lst_a);
	if (pos == 1)
		ra(lst_a);
	else if (pos == 2)
	{
		ra(lst_a);
		ra(lst_a);
	}
	else if (pos == 3)
		rra(lst_a);
	pb(lst_a, lst_b);
	three(lst_a);
	pa(lst_a, lst_b);
}

int	get_min_pos(t_lists *lst)
{
	int		min;
	int		pos;
	int		i;
	t_lists	*tmp;

	pos = 0;
	i = 0;
	tmp = lst;
	min = lst->content;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	five(t_lists **lst_a, t_lists **lst_b)
{
	int	pos;

	pos = get_min_pos(*lst_a);
	rotate_to_min(lst_a, pos, 5);
	pb(lst_a, lst_b);
	pos = get_min_pos(*lst_a);
	rotate_to_min(lst_a, pos, 4);
	pb(lst_a, lst_b);
	three(lst_a);
	pa(lst_a, lst_b);
	pa(lst_a, lst_b);
}
