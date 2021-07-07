#include "so_long.h"
int	ft_maplines(char *argv1, t_game *game)
{
	int		fd;
	int		size;
	char	*line;

	size = 0;
	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		ft_errors(2);
	while (get_next_line(fd, &line) > 0)
	{
		size++;
		free(line);
	}
	free(line);
	close(fd);
	game->height = size + 1;
	return (game->height);
}

void	ft_create_map2(t_game *game, char *argv1)
{
	int i;
	int fd;
	char *line;

	i = 0;
	game->map = malloc(ft_maplines(argv1, game) * sizeof(char *));
	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		ft_errors(2);
	while (get_next_line(fd, &line) > 0)
	{
		game->map[i] = line;
		game->width = ft_stlen(game->map[i]);
		ft_check_symb(game, game->map[i]);
		i++;
	}
	game->map[i] = line;
	ft_check_symb(game, game->map[i]);
	free(line);
	if (!game->map)
		ft_errors(3);
	check_size(game);
	ft_check_epc(game);
	ft_border_checker(game);
	ft_check_up_bord(game);
	close(fd);
}

void	ft_check_symb(t_game *game, char *mapi)
{
	int c;

	c = 0;
	while (mapi[c])
	{
		if (str_char("01CEP", mapi[c]) == 0)
		{
			write(1, "map valid error", 15);
			exit(1);
		}
		ft_count_epc(mapi[c],game);
		c++;
	}
}

void	ft_free_array(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}