/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:16:38 by miltavar          #+#    #+#             */
/*   Updated: 2025/06/23 13:57:12 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	list_tab(t_lists **lst_a, int i)
{
	int		size;
	int		*tab;
	t_lists	*tmp;

	tab = malloc(sizeof(int) * (size = ft_lstsize_ps(*lst_a)));
	if (!tab)
		return (-1);
	tmp = *lst_a;
	i = 0;
	while (tmp)
	{
		tab[i++] = tmp->content;
		tmp = tmp->next;
	}
	tab = sortint(tab, size);
	tmp = *lst_a;
	while (tmp)
	{
		i = 0;
		while (i < size && tab[i] != tmp->content)
			i++;
		tmp->content = i;
		tmp = tmp->next;
	}
	return (free(tab), 0);
}

int	get_chunk_count(int size)
{
	if (size <= 100)
		return (5);
	else if (size <= 200)
		return (6);
	else if (size <= 300)
		return (8);
	else if (size <= 400)
		return (10);
	else if (size <= 500)
		return (11);
	else if (size <= 1000)
		return (13);
	else
		return (18);
}

int	*sortint(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
				swapint(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
	return (tab);
}

void	sort_small(t_lists **lst_a, t_lists **lst_b)
{
	int	size;

	size = ft_lstsize_ps(*lst_a);
	while (size > 3)
	{
		if (get_min_pos(*lst_a) <= size / 2)
			while (get_min_pos(*lst_a) != 0)
				ra(lst_a, lst_b);
		else
			while (get_min_pos(*lst_a) != 0)
				rra(lst_a);
		pb(lst_a, lst_b);
		size--;
	}
	three(lst_a, lst_b);
	while (*lst_b)
		pa(lst_a, lst_b);
}
