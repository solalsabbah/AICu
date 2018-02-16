

#include "main.h"

void	printmatch(int	*tab, s_list *list)
{
	int x;
	int nb;

	x = 0;
	while (x <= list->line)
	{	 	
		nb = tab[x];
		while (nb != 0) 
		{	
			ft_putchar('|');
			nb--;
		}
		ft_putchar('\n');
		x++;
	}
}

int playgame(int *tab, s_list *list)
{
	while(1)
	{
		printmatch(tab, list);
		computer_resolve(tab, list);
		if (tab[0] == 0 && list->line == 0)
		{
			free(tab);
			return (0);
		}
		printmatch(tab, list);
		if (list->win == 1)
		{
			free(tab);
			return (0);
		}
		if (!(player_resolve(tab, list)))
		{
			free(tab);
			return (0);
		}
	}
}

int readfile(char *str, int *tab, s_list *list, int fd)
{
	if (fd == 0)
		tab = get_standart_int_cmd(fd, list);
	else
		tab = get_user_int_cmd(fd, str, list);
	if (tab == NULL)
		return (0);
	playgame(tab, list);
	return (1);
}

int main(int argc, char **argv)
{
	int		*tab;
	s_list	list;
	int		fd;

	tab = NULL;
	list.win = 0;
	if (argc > 2) 
	{
		ft_printf("The programme requires one or no argument\n");
		return (0);
	}
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (-1);
		if (readfile(argv[1], tab, &list, fd) == -1)
			return (0);
	}
	else if (readfile(argv[1], tab, &list, 0) == -1)
		return (0);
}
