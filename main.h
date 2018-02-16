#ifndef MAIN_H
# define MAIN_H

# include "get_next_line.h"
# include "ft_printf/includes/ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct		t_list
{
	int		line;
	int		win;
}					s_list;


int					ft_printf(char *format, ...);

char		**ft_strsplitwhitespace(char *str, char c1, char c2);
char		*get_user_char_cmd2(int fd);
int			*get_standart_int_cmd(int fd, s_list *list);
int 		*get_user_int_cmd(int fd, char *file, s_list *list);
void		computer_resolve(int *tab, s_list *list);
int		player_resolve(int *tab, s_list *list);
int			get_user_other_cmd(int fd);
char		*get_user_char_cmd(int fd);
void		printmatch(int	*tab, s_list *line);
int			readfile(char *str, int *tab, s_list *list, int fd);
#endif
