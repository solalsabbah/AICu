
#include "main.h"

int 		*get_user_int_cmd(int fd, char *file, s_list *list)
{
	char *str;
	int *result;
	int i;
	int x;
	int line;

	x = 0;
	line = 0;
	while ((str = get_user_char_cmd(fd)))
	{
		free(str);
		line++;
	}
	close(fd);
	if (!(result = malloc(sizeof(int) * line)))
		return (NULL);
	fd = open(file, O_RDONLY);
	while ((str = get_user_char_cmd(fd)))
	{
		i = 0;
		while (str[i])
		{
			if (!(ft_isdigit(str[i])))
			{
				ft_putstr("ERROR\n");
				free(str);
				return (NULL);
			}
			i++;
		}
		if (ft_atoi(str) < 1 || ft_atoi(str) > 10000)
		{
			ft_putstr("ERROR\n");
			free(str);
			return (NULL);
		}
		result[x] = ft_atoi(str);
		x++;
		free(str);
	}
	list->line = x - 1;
	close(fd);
	return (result);
}

int		*get_standart_int_cmd(int fd, s_list *list)
{
	char *str;
	int *result;
	char **tab;
	int i;

	i = 0;
	str = get_user_char_cmd2(fd);
	if (ft_strcmp(str, "ERROR") == 0)
	{
		ft_putstr("ERROR\n");
		return (NULL);
	}
	tab = ft_strsplitwhitespace(str, ' ', '*');
	free(str);
	while (tab[i])
		i++;
	if (!(result = malloc(sizeof(char) * i)))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		result[i] = ft_atoi(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	list->line = i - 1;
	return (result);
}

int		get_user_other_cmd(int fd)
{
	char *line;
	int i;

	fd = 0;
	i = 0;
	while (1)
	{
		line = get_user_char_cmd(0);
		if (ft_strcmp(line, "ERROR") == 0)
			return (-1);
		while (line[i])
		{
			if (!(ft_isdigit(line[i])))
			{
				ft_putstr("ERROR\n");
				free(line);
				return (-1);
			}
			i++;
		}
		if (!line[i])
		{
			i = ft_atoi(line);
			free(line);
			return (i);
		}
		free(line);
	}
}

char		*get_user_char_cmd2(int fd)
{
	char *line;
	char *str;
	char *tmp;
	int i;

	i = 0;
	str = "";
	if (get_next_line(fd, &line) == -1)
		return ("ERROR");
	if (ft_atoi(line) < 1 || ft_atoi(line) > 10000)
	{
		free(line);
		return("ERROR");
	}
	while (ft_strcmp(line, "") != 0)
	{
		tmp = ft_strjoin(str, line);
		free(line);
		if (i)
			free(str);
		str = ft_strjoin(tmp, " ");
		free(tmp);
		if (get_next_line(fd, &line) == -1)
			return("ERROR");
		if ((ft_atoi(line) < 1 || ft_atoi(line) > 10000) && ft_strcmp(line, "") != 0)
		{
			free(line);
			free(str);
			return("ERROR");
		}
		i++;
		if (ft_strcmp(line, "") == 0)
			free(line);
	}
	return (str);
}

char		*get_user_char_cmd(int fd)
{
	char *line;
	int stock;

	line = NULL;
	stock = get_next_line(fd, &line);
	if (stock == -1)
	{
		ft_putstr("ERROR\n");
		return ("ERROR");
	}
	return (line);
}
