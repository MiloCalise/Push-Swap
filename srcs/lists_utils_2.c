/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:34:39 by miltavar          #+#    #+#             */
/*   Updated: 2025/06/23 14:04:22 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstadd_front_ps(t_lists **lst, t_lists *new)
{
	new->next = *lst;
	*lst = new;
}

void	swap(t_lists **lst)
{
	int	tmp;

	if (lst && (*lst) && (*lst)->next)
	{
		tmp = (*lst)->content;
		(*lst)->content = (*lst)->next->content;
		(*lst)->next->content = tmp;
	}
}

void	push(t_lists **dest, t_lists **src)
{
	t_lists	*tmp;

	if (!(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = NULL;
	if (!*dest)
		*dest = tmp;
	else
		ft_lstadd_front_ps(dest, tmp);
}

int	rotate(t_lists **lst)
{
	t_lists	*tmp;

	if (!lst)
		return (0);
	if (ft_lstsize_ps(*lst) == 1)
		return (0);
	tmp = *lst;
	tmp = ft_lstlast_ps(tmp);
	tmp->next = ft_lstnew_ps((*lst)->content);
	if (!tmp->next)
		return (-1);
	tmp = (*lst)->next;
	free(*lst);
	*lst = tmp;
	return (0);
}

void	reverse_rotate(t_lists **lst)
{
	t_lists	*prev;
	t_lists	*last;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	prev = NULL;
	last = *lst;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *lst;
	*lst = last;
}
