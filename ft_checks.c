#include "so_long.h"
void	check_size(t_game *game)
{
	int i;

	i = 0;
	game->width = ft_stlen(game->map[i]);
	i++;
	while (i < game->height)
	{
		if (ft_stlen(game->map[i]) != game->width)
		{
			write(1, "invalid size map", 16);
			exit(1);
		}
		i++;
	}
}

void	ft_count_epc(char map, t_game *game)
{
	if (map == 'E')
		game->map_e = game->map_e + 1;
	if (map == 'P')
		game->map_p = game->map_p + 1;
	if (map == 'C')
		game->map_c = game->map_c + 1;
}

void	ft_check_epc(t_game *game)
{
	if (game->map_p != 1)
	{
		write(1, "player must be One", 18);
		ft_free_array(game->map);
		exit(1);
	}
	if (game->map_e  < 1)
	{
		write(1, "Portal Gde", 10);
		ft_free_array(game->map);
		exit(1);
	}
	if (game->map_c < 1)
	{
		write(1, "gde money", 9);
		ft_free_array(game->map);
		exit(1);
	}
}

void	ft_border_checker(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		if (game->map[i][0] == '1' && game->map[i][ft_stlen(game->map[i]) - 1] == '1')
			i++;
		else
			ft_errors(4);
	}
	i = 0;
	while (game->map[i][j] != '\0')
	{
		if (game->map[i][j] != '1')
			ft_errors(5);
		j++;
	}
}

void	ft_check_up_bord(t_game *game)
{
	int i;
	int j;

	j = 0;
	i = game->height;
	while (game->map[i][j])
	{
		if (game->map[i][j] != '1')
			ft_errors(5);
		j++;
	}
}
