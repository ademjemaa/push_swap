/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:08:06 by adjemaa           #+#    #+#             */
/*   Updated: 2021/04/02 18:13:37 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			error_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int			min_val(t_stack *stack_a)
{
	int		min;
	t_node	*tmp;

	tmp = stack_a->stack;
	min = stack_a->stack->value;
	while (tmp != NULL)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

t_stack		*free_list(t_stack *stack_a)
{
	t_node	*tmp;
	t_move	*mov;
	int		i;

	i = -1;
	while (++i < stack_a->len)
	{
		tmp = stack_a->stack;
		if (i < stack_a->len - 1)
			stack_a->stack = stack_a->stack->next;
		free(tmp);
	}
	if (stack_a->len != 0)
	{
		i = stack_a->total + 1;
		while (--i > 0)
		{
			mov = stack_a->move;
			stack_a->move = stack_a->move->next;
			free(mov->mov);
			free(mov);
		}
	}
	free(stack_a);
	return (NULL);
}

void		exec_r(t_stack *stack_a, t_stack *stack_b, int con)
{
	t_node *tmp;

	if (con == 1)
		exec_r(stack_b, stack_a, 0);
	if (stack_a->len < 2)
		return ;
	tmp = stack_a->stack;
	stack_a->stack->prev = lstlast(stack_a->stack);
	lstlast(stack_a->stack)->prev->next = NULL;
	stack_a->stack = stack_a->stack->prev;
	stack_a->stack->next = tmp;
	stack_a->stack->prev = NULL;
}

void		exec_rrr(t_stack *stack_a, t_stack *stack_b, int con)
{
	t_node *tmp;

	if (con == 1)
		exec_rrr(stack_b, stack_a, 0);
	if (stack_a->len < 2)
		return ;
	tmp = stack_a->stack->next;
	stack_a->stack->prev = lstlast(stack_a->stack);
	lstlast(stack_a->stack)->next = stack_a->stack;
	stack_a->stack->next = NULL;
	stack_a->stack = tmp;
	tmp->prev = NULL;
}
