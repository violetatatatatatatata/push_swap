/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:07:25 by avelandr          #+#    #+#             */
/*   Updated: 2025/05/13 16:16:22 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

void	sortdos(t_list *a)
{
	if (*(int *)(a->content) > *(int *)(a->next->content))
		sa(&a);
}

void	sorttres(t_list *a)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(a->content);
	second = *(int *)(a->next->content);
	third = *(int *)(a->next->next->content);
	if (first > second && first < third)
		sa(&a);
	else if (first > second && second > third)
	{
		sa(&a);
		rra(&a);
	}
	else if (first > third && second < third)
		ra(&a);
	else if (first < second && first > third)
		rra(&a);
	else if (first < second && second > third)
	{
		sa(&a);
		ra(&a);
	}
}

void	sort_four_or_five(t_stacks *s)
{
	if (ft_lstsize(s->a) == 4)
	{
		while (*(int *)(s->a->content) != minlst(s->a))
		{
			if (get_pos(s->a, minlst(s->a)) <= ft_lstsize(s->a) / 2)
				ra(&s->a);
			else
				rra(&s->a);
		}
		pb(&s->a, &s->b);
		sorttres(s->a);
		pa(&s->a, &s->b);
	}
	else if (ft_lstsize(s->a) == 5)
	{
		while (*(int *)(s->a->content) != minlst(s->a))
			ra(&s->a);
		pb(&s->a, &s->b);
		while (*(int *)(s->a->content) != minlst(s->a))
			ra(&s->a);
		pb(&s->a, &s->b);
		sorttres(s->a);
		pa(&s->a, &s->b);
		pa(&s->a, &s->b);
	}
}

void	selector(t_stacks *stacks)
{
	int	size;

	size = ft_lstsize(stacks->a);
	if (checkorder(stacks->a) || size < 2)
		return ;
	if (size == 2)
		sortdos(stacks->a);
	if (size == 3)
		sorttres(stacks->a);
	else if (size <= 5)
		sort_four_or_five(stacks);
	else
	{
		index_stack(stacks->a);
		radix_sort(&stacks->a, &stacks->b);
	}
}
