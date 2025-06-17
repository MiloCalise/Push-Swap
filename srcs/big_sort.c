/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:50:39 by miltavar          #+#    #+#             */
/*   Updated: 2025/06/17 16:31:20 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_max_pos(t_lists *lst)
{
	int	max;
	int	pos;
	int	i;

	if (!lst)
		return (0);
	max = lst->content;
	pos = 0;
	i = 0;
	while (lst)
	{
		if (lst->content > max)
		{
			max = lst->content;
			pos = i;
		}
		lst = lst->next;
		i++;
	}
	return (pos);
}

void	push_back(t_lists **lst_a, t_lists **lst_b)
{
	int	pos;

	while (*lst_b)
	{
		pos = find_max_pos(*lst_b);
		if (pos <= ft_lstsize_ps(*lst_b) / 2)
			while (pos-- > 0)
				rb(lst_b);
		else
			while (pos++ < ft_lstsize_ps(*lst_b))
				rrb(lst_b);
		pa(lst_a, lst_b);
	}
}

int	exists_in_range(t_lists *lst, int min, int max)
{
	while (lst)
	{
		if (lst->content >= min && lst->content < max)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	find_pos_in_range(t_lists *lst, int min, int max)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->content >= min && lst->content < max)
			return (i);
		lst = lst->next;
		i++;
	}
	return (0);
}

t_lists	*ft_lstlast_ps(t_lists *lst)
{
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
