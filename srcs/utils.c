/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:34:20 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/23 15:26:29 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

long	calc_res(const char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

long	ft_atol(const char *nptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (is_whitespace(nptr[i]) == 1)
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			sign = sign * -1;
		i++;
	}
	return (calc_res(nptr + i) * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
int	check_occ_split(char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[j])
		{
			if (i == j)
				j++;
			else if (ft_strcmp(strs[i], strs[j]) == 0)
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}
