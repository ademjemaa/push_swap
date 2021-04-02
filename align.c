/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:33:04 by adjemaa           #+#    #+#             */
/*   Updated: 2021/04/02 18:11:22 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		test_medians(t_stack *stack_b, int tech, int argc, char **argv)
{
	t_stack	*stackone;
	t_stack	*stacktwo;
	int		j;
	int		max;

	max = 800000;
	stack_b->total = tech - 1;
	while (stack_b->total < tech * 3)
	{
		stackone = check_values(argc, argv);
		stacktwo = init_stack();
		exec_quarter_algo(stackone, stacktwo, stack_b->total);
		if (stackone->total < max)
		{
			max = stackone->total;
			j = stack_b->total;
		}
		stackone = free_list(stackone);
		stacktwo = free_list(stacktwo);
		(stack_b->total)++;
	}
	return (j);
}

void	add_back(t_stack *stack_a, char *str)
{
	t_move	*elem;
	t_move	*tmp;

	elem = malloc(sizeof(t_move));
	elem->mov = str;
	elem->next = NULL;
	tmp = stack_a->move;
	if (stack_a->total == 0)
	{
		stack_a->move = elem;
		stack_a->total = 1;
		stack_a->move->next = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
		stack_a->total++;
	}
}

void	fix_b_three(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->stack->value > stack_b->stack->next->value)
	{
		if (lstlast(stack_b->stack)->value < stack_b->stack->value)
			write_exec(stack_a, stack_b, "RRB");
		else
		{
			write_exec(stack_a, stack_b, "PA");
			if (lstlast(stack_b->stack)->value < lstlast(stack_a->stack)->value)
				write_exec(stack_a, stack_b, "RB");
			else
				write_exec(stack_a, stack_b, "RR");
		}
	}
	else if (stack_b->stack->value > lstlast(stack_b->stack)->value)
		write_exec(stack_a, stack_b, "RB");
}

int		optimal_path_b(t_stack *stack_b)
{
	t_node	*tmp;
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (stack_b->len == 0)
		return (0);
	tmp = stack_b->stack;
	while (tmp && ++i)
	{
		if (tmp->value == min_val(stack_b) ||
			tmp->value == max_val(stack_b))
			j += i;
		tmp = tmp->next;
	}
	if ((stack_b->stack->value == min_val(stack_b) ||
		stack_b->stack->value == max_val(stack_b)) && j == stack_b->len)
		return (2);
	if (j - 2 <= stack_b->len)
		return (1);
	return (0);
}

void	align_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;
	int		i;

	tmp = stack_a->stack;
	i = 0;
	while (tmp && tmp->value != min_val(stack_a) && ++i)
		tmp = tmp->next;
	while (lstlast(stack_a->stack)->value != min_val(stack_a))
	{
		if (i < stack_a->len / 2)
			double_rot(stack_a, stack_b, "RRA");
		else
			double_rot(stack_a, stack_b, "RA");
	}
}
