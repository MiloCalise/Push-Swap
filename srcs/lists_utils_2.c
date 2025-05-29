/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:34:39 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/28 13:11:26 by miltavar         ###   ########.fr       */
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

	if (lst && (*lst)->content && (*lst)->next)
	{
		tmp = (*lst)->content;
		(*lst)->content = (*lst)->next->content;
		(*lst)->next->content = tmp;
	}
}

t_lists	*push(t_lists **dest, t_lists **src)
{
	t_lists	*tmp;

	if (!(*src))
		return (NULL);
	tmp = *src;
	if (!(*dest))
		*dest = ft_lstnew_ps((*src)->content);
	else
		ft_lstadd_front_ps(dest, ft_lstnew_ps((*src)->content));
	(*src) = (*src)->next;
	free(tmp);
	return (*dest);
}

void	rotate(t_lists **lst)
{
	int	temp;
	t_lists	*tmp;

	if (!(*lst)->next)
		return ;
	if ((*lst) && (*lst)->content)
		temp = (*lst)->content;
	tmp = (*lst);
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next;
	}
	tmp->content = temp;
}
void	reverse_rotate(t_lists **lst)
{
	int	temp;
	t_lists	*tmp;

	if (!(*lst)->next)
		return ;
	tmp = (*lst);
	while (tmp->next)
	{
		tmp->next->content = tmp->content;
		tmp = tmp->next;
	}
	temp = tmp->content;
	(*lst)->content = temp;
}
