/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:20:45 by miltavar          #+#    #+#             */
/*   Updated: 2025/06/17 11:05:52 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_not_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_occ_argv(int argc, char **argv, int j)
{
	int	i;

	i = 1;
	if (i == j)
		i++;
	while (i < argc)
	{
		if (i == j)
			i++;
		if (i == argc)
			return (1);
		if (ft_strcmp(argv[j], argv[i]) != 0)
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_str(char **argv)
{
	char	**strs;
	int		i;

	i = 0;
	strs = ft_split(argv[1], ' ');
	if (!strs)
		return (0);
	if (!check_occ_split(strs))
	{
		free_split(strs);
		ft_putstr_fd("Error\n", 2);
		exit (0);
	}
	while (strs[i])
	{
		if (!do_checks(strs[i]))
		{
			ft_putstr_fd("Error\n", 2);
			free_split(strs);
			exit (0);
		}
		i++;
	}
	free_split(strs);
	return (1);
}

int	do_checks(char *str)
{
	long	check;

	if (!check_not_digit(str))
		return (0);
	check = atol(str);
	if (check > 2147483647 || check < -2147483648)
		return (0);
	return (1);
}

void	free_split(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}
