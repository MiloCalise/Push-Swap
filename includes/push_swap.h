/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:38:44 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/28 13:05:48 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_lists
{
	int				content;
	struct s_lists	*next;
}					t_lists;

long	ft_atol(const char *nptr);

int		ft_strcmp(char *s1, char *s2);
int		check_not_digit(char *str);
int		check_occ_argv(int argc, char **argv, int j);
int		check_occ_split(char **strs);
int		do_checks(char *str);
int		check_str(char **argv);
int	ft_lstsize_ps(t_lists *lst);

void	free_split(char **split, int i);
void	ft_lstprint(t_lists *lst);
void	ft_lstadd_back_ps(t_lists **lst, t_lists *new);
void	ft_lstadd_front_ps(t_lists **lst, t_lists *new);
void	swap(t_lists **lst);
void	rotate(t_lists **lst);
void	reverse_rotate(t_lists **lst);
void	free_list(t_lists **lst);
void	push_to_b(t_lists **lst_a, t_lists **lst_b);

t_lists	*split_to_list(char **argv);
t_lists	*ft_lstnew_ps(int content);
t_lists	*argv_to_list(int argc, char **argv);
t_lists	*push(t_lists **dest, t_lists **src);

#endif
