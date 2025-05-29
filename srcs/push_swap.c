/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:12:35 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/28 15:03:35 by miltavar         ###   ########.fr       */
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

int	main(int argc, char ** argv)
{
	t_lists	*lst_a;
	t_lists	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2 )
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
	ft_putstr_fd("liste a = \n", 1);
	ft_lstprint(lst_a);
	push_to_b(&lst_b, &lst_a);
	ft_putstr_fd("liste a = \n", 1);
	ft_lstprint(lst_a);
	ft_putstr_fd("liste b = \n", 1);
	ft_lstprint(lst_b);
	ft_putchar_fd('\n', 1);
	free_list(&lst_a);
	free_list(&lst_b);
	return (0);
}
