#include "so_long.h"
int	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(1);
	return (1);
}

void	ft_press_w(t_game *game)
{
	if ((game->map[game->pos_y - 1][game->pos_x] == '1')
		|| (game->map[game->pos_y - 1][game->pos_x] == 'E'
			&& game->count_coins != game->map_c))
		return ;
	else if (game->map[game->pos_y - 1][game->pos_x] == 'C')
	{
		game->count_coins = game->count_coins + 1;
		game->map[game->pos_y - 1][game->pos_x] = '0';
	}
	if (game->map[game->pos_y - 1][game->pos_x] == 'E')
	{
		if (game->count_coins == game->map_c)
		{
			game->p_mov++;
			end_game(game);
		}
	}
	game->pos_y = game->pos_y - 1;
	game->p_mov = game->p_mov + 1;
	ft_putnbr_fd(game->p_mov, 1);
	write(1, "\n", 1);
}

void	ft_press_a(t_game *game)
{
	if ((game->map[game->pos_y][game->pos_x - 1] == '1')
		|| (game->map[game->pos_y][game->pos_x - 1] == 'E'
			&& game->count_coins != game->map_c))
		return ;
	else if (game->map[game->pos_y][game->pos_x -1] == 'C')
	{
		game->count_coins = game->count_coins + 1;
		game->map[game->pos_y][game->pos_x - 1] = '0';
	}
	if (game->map[game->pos_y][game->pos_x - 1] == 'E')
	{
		if (game->count_coins == game->map_c)
		{
			game->p_mov++;
			end_game(game);
		}
	}
	game->pos_x = game->pos_x - 1;
	game->p_mov = game->p_mov + 1;
	ft_putnbr_fd(game->p_mov, 1);
	write(1, "\n", 1);
}

void	ft_press_s(t_game *game)
{
	if ((game->map[game->pos_y + 1][game->pos_x] == '1')
		|| (game->map[game->pos_y + 1][game->pos_x] == 'E'
			&& game->count_coins != game->map_c))
		return ;
	else if (game->map[game->pos_y + 1][game->pos_x] == 'C')
	{
		game->count_coins = game->count_coins + 1;
		game->map[game->pos_y + 1][game->pos_x] = '0';
	}
	if (game->map[game->pos_y + 1][game->pos_x] == 'E')
	{
		if (game->count_coins == game->map_c)
		{
			game->p_mov++;
			end_game(game);
		}
	}
	game->pos_y = game->pos_y + 1;
	game->p_mov = game->p_mov + 1;
	ft_putnbr_fd(game->p_mov, 1);
	write(1, "\n", 1);
}

void	ft_press_d(t_game *game)
{
	if ((game->map[game->pos_y][game->pos_x + 1] == '1')
		|| (game->map[game->pos_y][game->pos_x + 1] == 'E'
			&& game->count_coins != game->map_c))
		return ;
	else if (game->map[game->pos_y][game->pos_x + 1] == 'C')
	{
		game->count_coins = game->count_coins + 1;
		game->map[game->pos_y][game->pos_x + 1] = '0';
	}
	if (game->map[game->pos_y][game->pos_x + 1] == 'E')
	{
		if (game->count_coins == game->map_c)
		{
			game->p_mov++;
			end_game(game);
		}
	}
	game->pos_x = game->pos_x + 1;
	game->p_mov = game->p_mov + 1;
	ft_putnbr_fd(game->p_mov, 1);
	write(1, "\n", 1);
}
