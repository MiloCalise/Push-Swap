/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:14:39 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/28 15:08:31 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void free_list(t_lists **lst)
{
	t_lists *tmp;

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

void	push_to_b(t_lists **dest, t_lists **src)
{
	if (!src || !*src || !(*src)->next)
		return ;
	while ((*src)->next)
	{
		if ((*src)->next->content < (*src)->content)
		{
			push(dest, src);
		}
		else
		{
			swap(src);
		}
	}
}

