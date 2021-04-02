/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:42:54 by adjemaa           #+#    #+#             */
/*   Updated: 2021/04/02 17:08:53 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		average_pos(t_stack *stack_a, int med, int med2)
{
	int		i;
	int		j;
	t_node	*tmp;

	i = 1;
	j = 0;
	tmp = stack_a->stack;
	while (tmp)
	{
		if (tmp->value <= med && tmp->value > med2 && i <= (stack_a->len / 2))
			j += -i;
		else if (tmp->value <= med && tmp->value >
			med2 && i > (stack_a->len / 2))
			j += (stack_a->len) - i;
		i++;
		tmp = tmp->next;
	}
	return (j);
}

void	show_moves(t_stack *stack_a)
{
	t_move	*move;

	move = stack_a->move;
	while (move)
	{
		ft_putstr_fd(move->mov, 1);
		move = move->next;
	}
}

void	push_rotate_stack(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->len != 0)
	{
		if (stack_b->len == 3)
			fix_b_three(stack_a, stack_b);
		if (lstlast(stack_b->stack)->value == max_val(stack_b))
			write_exec(stack_a, stack_b, "PA");
		else if (lstlast(stack_b->stack)->value == min_val(stack_b))
		{
			write_exec(stack_a, stack_b, "PA");
			if (!optimal_path_b(stack_b) && !rot_b_stack(stack_b))
				write_exec(stack_a, stack_b, "RR");
			else
				write_exec(stack_a, stack_b, "RA");
		}
		else
			opti_rot_b(stack_a, stack_b);
	}
}

int		choose_ret(t_stack *stack_a, int rank, int med, int val)
{
	if (rank >= med)
	{
		if (stack_a->len % 2 == 1)
			return (val);
		else if (rank == med)
			return ((val + find_med(stack_a, rank + 1, val)) / 2);
		else
			return (val);
	}
	return (find_med(stack_a, rank + 1, val));
}

int		find_med(t_stack *stack_a, int rank, int cur)
{
	t_node	*tmp;
	int		med;
	int		val;

	med = (stack_a->len % 2 == 1) ? (stack_a->len + 1) / 2 : stack_a->len / 2;
	tmp = stack_a->stack;
	val = min_val(stack_a);
	while (tmp)
	{
		if (tmp->value > val)
			if (rank == 1 || tmp->value < cur)
				val = tmp->value;
		tmp = tmp->next;
	}
	return (choose_ret(stack_a, rank, med, val));
}
