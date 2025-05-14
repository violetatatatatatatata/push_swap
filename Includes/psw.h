/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:54:43 by avelandr          #+#    #+#             */
/*   Updated: 2025/05/14 18:25:16 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_H
# define PSW_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}	t_stacks;

// utils.c
t_list		**lstnum(t_list *lst, int num);
int			minlst(t_list *lst);
void		ft_printlist(t_list *a);
int			get_index(int *arr, int size, int val);
int			get_pos(t_list *lst, int val);

// check.c
int			checkorder(t_list *ord);
int			norep(char **argv, int argc);
int			checknum(int argc, char **argv);

// algorithm.c
void		radix_sort(t_list **a, t_list **b);
void		radix_pass(t_list **a, t_list **b, int i, int size);
void		index_stack(t_list *a);
int			*list2array(t_list *a, int size);
void		sort_array(int *arr, int size);

// sortone.c 
void		sortdos(t_list *a);
void		sorttres(t_list *a);
void		sort_four_or_five(t_stacks *s);
void		selector(t_stacks *stacks);

// leer_args.c
int			*list_nums(char const *str);
t_stacks	init_stacks(int *nums, int size);
t_list		*new_stack_node(int n);
void		free_stacks(t_stacks *s);
void		liberar_array(char **array);

/*	MOVIMIENTOS	*/

// swap.c
void		swap(t_list **x);
void		sa(t_list **x);
void		sb(t_list **x);
void		ss(t_list **x, t_list **y);

// push.c
void		push(t_list **x, t_list **y);
void		pa(t_list **x, t_list **y);
void		pb(t_list **y, t_list **x);

// rotate.c
void		rotate(t_list **x);
void		ra(t_list **x);
void		rb(t_list **x);

// reverse_rotate.c
void		reverse_rotate(t_list **x);
void		rra(t_list **x);
void		rrb(t_list **x);
void		rrr(t_list **x, t_list **y);

#endif
