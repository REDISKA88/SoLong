#include "so_long.h"
void	ft_end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
}

void	ft_press_w(t_game *game, t_map *mp)
{
	if (mp->map[game->pos_y - 1][game->pos_x] == 1
		|| mp->map[game->pos_y - 1][game->pos_x] == 'E'
		&& game->coins != mp->map_c)
		return ;
	else if (mp->map[game->pos_x - 1][game->pos_y] == 'C')
	{
		game->coins = game->coins + 1;
		mp->map[game->pos_y - 1][game->pos_x] = '0';
	}
	if (mp->map[game->pos_y - 1][game->pos_x] == 'E')
	{
		if (game->coins == mp->map_c)
		{
			game->p_mov++;
			ft_end_game(game);
		}
	}
	game->pos_y = game->pos_y - 1;
	game->p_mov = game->p_mov + 1;
}

void ft_press_a(t_game *game, t_map *mp)
{
	if (mp->map[game->pos_y][game->pos_x - 1] == 1
		|| mp->map[game->pos_y][game->pos_x - 1] == 'E'
		   && game->coins != mp->map_c)
		return ;
	else if (mp->map[game->pos_y][game->pos_x -1] == 'C')
	{
		game->coins = game->coins + 1;
		mp->map[game->pos_y][game->pos_x - 1] = '0';
	}
	if (mp->map[game->pos_y][game->pos_x - 1] == 'E')
	{
		if (game->coins == mp->map_c)
		{
			game->p_mov++;
			ft_end_game(game);
		}
	}
	game->pos_y = game->pos_x - 1;
	game->p_mov = game->p_mov + 1;
}

void	ft_press_s(t_game *game, t_map *mp)
{
	if (mp->map[game->pos_y - 1][game->pos_x] == 1
		|| mp->map[game->pos_y - 1][game->pos_x] == 'E'
		   && game->coins != mp->map_c)
		return ;
	else if (mp->map[game->pos_y + 1][game->pos_x] == 'C')
	{
		game->coins = game->coins + 1;
		mp->map[game->pos_y + 1][game->pos_x] = '0';
	}
	if (mp->map[game->pos_y + 1][game->pos_x] == 'E')
	{
		if (game->coins == mp->map_c)
		{
			game->p_mov++;
			ft_end_game(game);
		}
	}
	game->pos_y = game->pos_y + 1;
	game->p_mov = game->p_mov + 1;
}

void ft_press_d(t_game *game, t_map *mp)
{
	if (mp->map[game->pos_y][game->pos_x + 1] == 1
		|| mp->map[game->pos_y][game->pos_x + 1] == 'E'
		   && game->coins != mp->map_c)
		return ;
	else if (mp->map[game->pos_y][game->pos_x + 1] == 'C')
	{
		game->coins = game->coins + 1;
		mp->map[game->pos_y][game->pos_x + 1] = '0';
	}
	if (mp->map[game->pos_y][game->pos_x + 1] == 'E')
	{
		if (game->coins == mp->map_c)
		{
			game->p_mov++;
			ft_end_game(game);
		}
	}
	game->pos_y = game->pos_x + 1;
	game->p_mov = game->p_mov + 1;
}