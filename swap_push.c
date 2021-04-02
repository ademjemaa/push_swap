/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:35:16 by adjemaa           #+#    #+#             */
/*   Updated: 2021/04/02 18:15:40 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_exec(t_stack *stack_a, t_stack *stack_b, char *str)
{
	add_back(stack_a, ft_strjoin(str, "\n"));
	execute(stack_a, stack_b, str);
}

void	exec_three_instr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->stack->value < stack_a->stack->next->value)
	{
		if (stack_a->stack->next->value < lstlast(stack_a->stack)->value)
		{
			write_exec(stack_a, stack_b, "SA");
			write_exec(stack_a, stack_b, "RRA");
		}
		else if (stack_a->stack->value > lstlast(stack_a->stack)->value)
		{
			write_exec(stack_a, stack_b, "SA");
			write_exec(stack_a, stack_b, "RA");
		}
		else
			write_exec(stack_a, stack_b, "RRA");
	}
	else
	{
		if (stack_a->stack->value > lstlast(stack_a->stack)->value)
			write_exec(stack_a, stack_b, "SA");
		else
			write_exec(stack_a, stack_b, "RA");
	}
}

void	pick(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	if (check_sorting(stack_a, stack_b))
		return ;
	if (stack_a->len == 2)
		exec_two_instr(stack_a, stack_b);
	if (stack_a->len == 3)
		exec_three_instr(stack_a, stack_b);
	if (stack_b->len == 3)
		exec_three_instr(stack_b, stack_b);
	if (stack_a->len > 3 && stack_a->len < 6)
		exec_five_instr(stack_a, stack_b);
	if (stack_a->len > 5 && stack_a->len < 150)
		exec_quarter_algo(stack_a, stack_b,
		test_medians(stack_b, 3, argc, argv));
	if (stack_a->len > 149)
		exec_quarter_algo(stack_a, stack_b,
		test_medians(stack_b, 5, argc, argv));
}

int		init_all(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	stack_b = init_stack();
	stack_a = check_values(argc, argv);
	pick(stack_a, stack_b, argc, argv);
	if (stack_a == NULL)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = init_stack();
	stack_a = check_values(argc, argv);
	if (stack_a == NULL)
		return (error_msg());
	pick(stack_a, stack_b, argc, argv);
	show_moves(stack_a);
	free_list(stack_a);
	free_list(stack_b);
}
