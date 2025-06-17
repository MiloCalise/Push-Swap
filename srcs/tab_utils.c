/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:16:38 by miltavar          #+#    #+#             */
/*   Updated: 2025/06/17 16:38:05 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	list_tab(t_lists **lst_a)
{
	int		size;
	int		*tab;
	int		i;
	t_lists	*tmp;

	tab = malloc(sizeof(int) * (size = ft_lstsize_ps(*lst_a)));
	tmp = *lst_a;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
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
	free(tab);
}

int	get_chunk_count(int size)
{
	 if (size <= 100)
		return (5);
	else if (size <= 200)
		return (9);
	else if (size <= 300)
		return (12);
	else if (size <= 400)
		return (15);
	else if (size <= 500)
		return (19);
	else
		return (25);
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

void	rotate_to_min(t_lists **lst_a, int pos, int max)
{
	if (pos <= max / 2)
		while (--pos >= 0)
			ra(lst_a);
	else
		while (++pos <= max)
			rra(lst_a);
}
