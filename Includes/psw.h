/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:46:22 by avelandr          #+#    #+#             */
/*   Updated: 2025/05/11 15:28:15 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include "libft.h"

typedef struct
{
	t_list	*a;
	t_list	*b;
}	t_stacks;

// utils.c
int			is_valid(int *nums, int size);
void		free_stacks(t_stacks *s);
t_list		**lstnum(t_list *lst, int num);
int			minlst(t_list *lst);
void		ft_printlist(t_list *a);

// check.c
int			checkorder(t_list *ord);
int			norep(char **argv, int argc);
int			checknum(int argc, char **argv);
int			checkargs(int argc, char **argv);

// algorithm.c
void		radix_sort(t_list **a, t_list **b);
void		index_stack(t_list *a);
int			*list2array(t_list *a, int size);
int			get_index(int *arr, int size, int val);
void		sort_array(int *arr, int size);

// sortone.c 
void		sortdos(t_list *a);
void		sorttres(t_list *a);
void		sort_small(t_stacks *s);
void		selector(t_stacks *stacks);

// leer_args.c
char		**leer_argumentos(char const *str);
size_t		 contar_args(char const *str);
int			*list_nums(char const *str);
void		liberar_array(char **array);
t_stacks    init_stacks(int *nums, int size);

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
