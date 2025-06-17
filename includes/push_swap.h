/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:38:44 by miltavar          #+#    #+#             */
/*   Updated: 2025/06/17 16:32:05 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

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
int		ft_lstsize_ps(t_lists *lst);
int		get_min_pos(t_lists *lst);
int		find_max_pos(t_lists *lst);
int		exists_in_range(t_lists *lst, int min, int max);
int		find_pos_in_range(t_lists *lst, int min, int max);
int		get_chunk_count(int size);
int		check_order(t_lists **lst_a);
int		find_pos(t_lists *lst, int value);

int		*sortint(int *tab, int size);

void	free_split(char **strs);
void	ft_lstprint(t_lists *lst);
void	ft_lstadd_back_ps(t_lists **lst, t_lists *new);
void	ft_lstadd_front_ps(t_lists **lst, t_lists *new);
void	swap(t_lists **lst);
void	rotate(t_lists **lst);
void	reverse_rotate(t_lists **lst);
void	free_list(t_lists **lst);
void	two(t_lists **lst_a);
void	three(t_lists **lst_a);
void	four(t_lists **lst_a, t_lists **lst_b);
void	push(t_lists **dest, t_lists **src);
void	pb(t_lists **lst_a, t_lists **lst_b);
void	pa(t_lists **lst_a, t_lists **lst_b);
void	rrb(t_lists **lst_b);
void	rra(t_lists **lst_a);
void	rrr(t_lists **lst_a, t_lists **lst_b);
void	ss(t_lists **lst_a, t_lists **lst_b);
void	rr(t_lists **lst_a, t_lists **lst_b);
void	ra(t_lists **lst_a);
void	rb(t_lists **lst_b);
void	sa(t_lists **lst_a);
void	sb(t_lists **lst_b);
void	swapint(int *a, int *b);
void	list_tab(t_lists **lst_a);
void	sort_chunk(t_lists **lst_a, t_lists **lst_b);
void	push_chunk(t_lists **lst_a, t_lists **lst_b, int min, int max);
void	push_back(t_lists **lst_a, t_lists **lst_b);
void	rotate_to_min(t_lists **lst, int pos, int max);

t_lists	*split_to_list(char **argv);
t_lists	*ft_lstnew_ps(int content);
t_lists	*argv_to_list(int argc, char **argv);
t_lists	*ft_lstlast_ps(t_lists *lst);

#endif
