/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:19:45 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 18:42:59 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		special_case(int *tab, s_list *list)
{
	int x;
	int tmp;
	int res;

	x = list->line;
	tmp = tab[x] / 4;
	res = tmp * 4 + 1;
	if (res == tab[x])
		res = tab[x] - 1;
	ft_printf("Computer play : %d\n", tab[x] - res);
	tab[x] = res;
	list->line -= tab[x] == 0 ? 1 : 0;
}

void		computer_resolve(int *tab, s_list *list)
{
	int x;

	x = list->line;
	if (x == -1 && tab[0] == 0)
	{
		ft_printf("\nComputer won ! Try again :-) \n");
		list->win = 1;
	}
	else if (tab[0] == 5 && tab[x] <= 3 && x == 1)
	{
		ft_printf("Computer play : %d\n", tab[x]);
		tab[x] = 0;
		list->line--;
	}
	else if (tab[x] == 5)
	{
		tab[x] = tab[x] - 1;
		ft_printf("Computer play : 1\n");
	}
	else if (tab[x] % 4 == 0)
	{
		tab[x] = tab[x] - 3;
		ft_printf("Computer play : 3\n");
		list->line -= tab[x] == 0 ? 1 : 0;
	}
	else
		special_case(tab, list);
}

int		player_resolve(int *tab, s_list *list)
{
	int result;
	int x;

	x = list->line;
	if (x == -1 && tab[0] == 0)
	{
		ft_printf("\nYou Won ! Well Done :-)\n");
		return (0);
	}
	while (1)
	{
		ft_putstr("You play :      ");
		result = get_user_other_cmd(0);
		if (result < 0)
			return (0);
		if (tab[x] - result >= 0 && result >= 1 && result <= 3)
		{
			tab[x] = tab[x] - result;
			if (tab[x] == 0)
				list->line--;
			return (1);
		}
		else
			ft_putstr("Your number is incorrect\n");
	}
}
