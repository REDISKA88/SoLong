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
	game->height = size;
	return (game->height);
}

void	ft_create_map2(t_game *game, char *argv1)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	game->map = malloc((ft_maplines(argv1, game) + 1) * sizeof(char *));
	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		ft_errors(2);
	while (get_next_line(fd, &line) > 0)
	{
		game->map[i] = line;
		game->width = ft_stlen(game->map[i]);
		i++;
	}
	game->map[i] = line;
	free(line);
	if (!game->map)
	{
		ft_errors(3);
		ft_free_array(game->map);
	}
	ft_valid_map(game);
	close(fd);
}

void	ft_valid_map(t_game *game)
{
	game->i = 0;
	while (game->i < game->height)
	{
		game->j = 0;
		while (game->map[game->i][game->j])
		{
			if (game->map[game->i][game->j] == 'P')
			{
				game->pos_y = game->i;
				game->pos_x = game->j;
				game->map_p = game->map_p + 1;
				game->map[game->i][game->j] = '0';
			}
			else if (game->map[game->i][game->j] == 'C')
				game->map_c = game->map_c + 1;
			else if (game->map[game->i][game->j] == 'E')
				game->map_e = game->map_e + 1;
			else if (str_char("01CPE", game->map[game->i][game->j]) == 0)
				ft_errors(6);
			game->j++;
		}
		game->i++;
	}
	ft_check_up_down(game);
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
