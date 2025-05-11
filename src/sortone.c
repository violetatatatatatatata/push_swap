/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:23:14 by avelandr          #+#    #+#             */
/*   Updated: 2025/05/11 15:41:50 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

void	sortdos(t_list *a)
{
	if (a->content > a->next->content)
		sa(&a);
}

void	sorttres(t_list *a)
{
	if (a->content > a->next->content)
		sa(&a);
}

void	sort_small(t_stacks *s)
{
	int		min;
	t_list	**target;
	t_list	*tmp;
	int		pos;

	while (ft_lstsize(s->a) > 3)
	{
		min = minlst(s->a);
		target = lstnum(s->a, min);
		tmp = s->a;
		pos = 0;
		while (tmp && tmp != *target)
		{
			tmp = tmp->next;
			pos++;
		}
		if (pos <= ft_lstsize(s->a) / 2)
			while (*target != s->a)
				ra(&s->a);
		else
			while (*target != s->a)
				rra(&s->a);
		pb(&s->a, &s->b);
	}
	sorttres(s->a);
	while (s->b)
		pa(&s->a, &s->b);
}

void    selector(t_stacks *stacks)
{
    int size;

    size = ft_lstsize(stacks->a);
    if (checkorder(stacks->a))
        return ;
    if (size == 0 || size == 1)
        return ;
    else if (size == 2)
        sortdos(stacks->a);
    else if (size == 3)
        sorttres(stacks->a);
    else if (size <= 5)
        sort_small(stacks);
    else
    {
        index_stack(stacks->a);
        radix_sort(&stacks->a, &stacks->b);
    }
}
