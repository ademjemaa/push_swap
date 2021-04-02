/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_instr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:49:07 by adjemaa           #+#    #+#             */
/*   Updated: 2021/04/02 16:29:32 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_two_instr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 2 && stack_a->stack->value <
		stack_a->stack->next->value)
		write_exec(stack_a, stack_b, "SA");
	if (stack_b->len == 2 && stack_b->stack->value <
		stack_b->stack->next->value)
		write_exec(stack_a, stack_b, "SB");
}

char	*optimal_path(t_stack *stack_a)
{
	int		i;
	int		j;
	int		med;
	t_node	*tmp;

	i = 1;
	j = 0;
	med = find_med(stack_a, 1, min_val(stack_a));
	tmp = stack_a->stack;
	while (tmp)
	{
		if (tmp->value >= med && stack_a->len >= 5 && i <= (stack_a->len / 2))
			j += -i - 1;
		if (tmp->value >= med && stack_a->len >= 5 && i > (stack_a->len / 2))
			j += i;
		i++;
		tmp = tmp->next;
	}
	if (j < 0)
		return ("RRA");
	return ("RA");
}

void	exec_five_instr(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->len > 3)
	{
		if (lstlast(stack_a->stack)->value == min_val(stack_a) ||
		(stack_a->len == 5 && (lstlast(stack_a->stack)->value ==
		find_quad_med(stack_a, 1, 5, min_val(stack_a)))))
			write_exec(stack_a, stack_b, "PB");
		else
			write_exec(stack_a, stack_b, optimal_path(stack_a));
	}
	if (!check_sorting(stack_a, NULL))
		exec_three_instr(stack_a, stack_b);
	if (stack_b->len == 2 && (stack_b->stack->value
		> stack_b->stack->next->value))
		write_exec(stack_a, stack_b, "SB");
	write_exec(stack_a, stack_b, "PA");
	if (stack_b->len == 1)
		write_exec(stack_a, stack_b, "PA");
}
