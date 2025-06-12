/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:14:39 by miltavar          #+#    #+#             */
/*   Updated: 2025/06/11 15:42:58 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_list(t_lists **lst)
{
	t_lists	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

int	ft_lstsize_ps(t_lists *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	pb(t_lists **lst_a, t_lists **lst_b)
{
	push(lst_b, lst_a);
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_lists **lst_a, t_lists **lst_b)
{
	push(lst_a, lst_b);
	ft_putstr_fd("pa\n", 1);
}

void	swapint(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
