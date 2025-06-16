/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:47:23 by miltavar          #+#    #+#             */
/*   Updated: 2025/06/12 11:00:15 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lists	*split_to_list(char **argv)
{
	char	**strs;
	int		i;
	t_lists	*lst_a;

	strs = ft_split(argv[1], ' ');
	if (!strs)
		exit (1);
	i = 1;
	lst_a = ft_lstnew_ps(ft_atoi(strs[0]));
	while (strs[i])
	{
		ft_lstadd_back_ps(&lst_a, ft_lstnew_ps(ft_atoi(strs[i])));
		i++;
	}
	free_split(strs);
	return (lst_a);
}

void	ft_lstprint(t_lists *lst)
{
	while (lst)
	{
		printf("%d ", lst->content);
		lst = lst->next;
	}
	printf("\n");
}

t_lists	*ft_lstnew_ps(int content)
{
	t_lists	*dst;

	dst = (t_lists *)malloc(sizeof(t_lists));
	if (!dst)
		return (NULL);
	dst->content = content;
	dst->next = NULL;
	return (dst);
}

void	ft_lstadd_back_ps(t_lists **lst, t_lists *new)
{
	t_lists	*tmp;

	if (!(*lst))
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

t_lists	*argv_to_list(int argc, char **argv)
{
	t_lists	*lst_a;
	int		i;

	lst_a = ft_lstnew_ps(ft_atoi(argv[1]));
	i = 2;
	while (i < argc)
	{
		ft_lstadd_back_ps(&lst_a, ft_lstnew_ps(ft_atoi(argv[i])));
		i++;
	}
	return (lst_a);
}
