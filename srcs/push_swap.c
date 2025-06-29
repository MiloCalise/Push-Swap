/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:12:35 by miltavar          #+#    #+#             */
/*   Updated: 2025/06/23 15:46:32 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_error(int argc, char **argv)
{
	int		i;
	long	check;

	i = 1;
	while (i < argc)
	{
		if (!check_not_digit(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			exit (0);
		}
		check = ft_atol(argv[i]);
		if (check > 2147483647 || check < -2147483648)
		{
			ft_putstr_fd("Error\n", 2);
			exit (0);
		}
		if (!check_occ_argv(argc, argv, i))
		{
			ft_putstr_fd("Error\n", 2);
			exit (0);
		}
		i++;
	}
	return (1);
}

void	sort_chunk(t_lists **lst_a, t_lists **lst_b)
{
	int	size;
	int	chunk_size;
	int	min;
	int	max;

	size = ft_lstsize_ps(*lst_a);
	if (size <= 10)
	{
		sort_small(lst_a, lst_b);
		return ;
	}
	chunk_size = size / get_chunk_count(size);
	min = 0;
	max = chunk_size;
	while (min < size)
	{
		push_chunk(lst_a, lst_b, min, max);
		min = max;
		max += chunk_size;
	}
	push_back(lst_a, lst_b);
}

void	push_chunk(t_lists **lst_a, t_lists **lst_b, int min, int max)
{
	int	pos;
	int	mid;

	mid = (min + max) / 2;
	while (exists_in_range(*lst_a, min, max))
	{
		pos = find_pos_in_range(*lst_a, min, max);
		if (pos <= ft_lstsize_ps(*lst_a) / 2)
			while (pos-- > 0)
				ra(lst_a, lst_b);
		else
			while (pos++ < ft_lstsize_ps(*lst_a))
				rra(lst_a);
		if ((*lst_a)->content < mid)
		{
			pb(lst_a, lst_b);
			rb(lst_b, lst_a);
		}
		else
			pb(lst_a, lst_b);
	}
}

void	distributor(t_lists **lst_a, t_lists **lst_b)
{
	int	size;
	int	i;

	size = ft_lstsize_ps(*lst_a);
	if (check_order(lst_a))
	{
		free_list(lst_a);
		return ;
	}
	if (size == 1)
		return ;
	else if (size == 2)
		two(lst_a);
	else if (size == 3)
		three(lst_a, lst_b);
	else if (size == 4)
		four(lst_a, lst_b);
	else if (size > 4)
	{
		i = list_tab(lst_a, 0);
		if (i >= 0)
			sort_chunk(lst_a, lst_b);
	}
	free_list(lst_a);
	free_list(lst_b);
}

int	main(int argc, char **argv)
{
	t_lists	*lst_a;
	t_lists	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		if (!check_str(argv))
			return (1);
		lst_a = split_to_list(argv);
	}
	else
	{
		if (!check_error(argc, argv))
			return (1);
		lst_a = argv_to_list(argc, argv);
	}
	distributor(&lst_a, &lst_b);
	return (0);
}
