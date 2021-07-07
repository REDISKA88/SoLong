#include "so_long.h"
void	ft_start_game(t_game *game)
{

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->height * 32,
							   game->width * 32, "SO LONG");
	ft_create_xpm(game);
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 33, 1L << 5, end_game, game);
	mlx_loop_hook(game->mlx, display, game);
	mlx_loop(game->mlx);
}

void	ft_create_xpm(t_game *game)
{
	game->player.img = mlx_xpm_file_to_image(game->mlx, "player.xpm",game->player
			.width, game->player.height);

	game->grass.img = mlx_xpm_file_to_image(game->mlx, "grass.xpm",game->grass
			.width, game->grass.height);
	game->coin.img = mlx_xpm_file_to_image(game->mlx, "player.xpm",game->coin
			.width, game->coin.height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "player.xpm",game->exit
			.width, game->exit.height);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "player.xpm",game->wall
			.width, game->wall.height);
}

void	ft_put_image(t_game *game, char c)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall.img,
								game->j * 32, game->i * 32);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit.img,
								game->j * 32, game->i * 32);
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->grass.img,
								game->j * 32, game->i * 32);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coin.img,
								game->j * 32, game->i * 32);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player.img,
								game->j * 32, game->i * 32);
}

int	display(t_game *game)
{
	game->i = 0;
	game->j = 0;
	while (game->i < game->height)
	{
		game->j = 0;
		while (game->j < game->width)
		{
			if (game->map[game->i][game->j] == '1')
				ft_put_image(game, '1');
			else if (game->map[game->i][game->j] == '0')
				ft_put_image(game, '0');
			else if (game->map[game->i][game->j] == 'E')
				ft_put_image(game, 'E');
			else if (game->map[game->i][game->j] == 'C')
				ft_put_image(game, 'C');
			else if (game->map[game->i][game->j] == 'P')
				ft_put_image(game, 'P');
			game->j = game->j + 1;
		}
		game->i = game->i + 1;
	}
	return (1);
}
int	key_hook(int code, t_game *game)
{
	if (code == 53)
		end_game(game);
	else if (code == 13)
		ft_press_w(game);
	else if (code == 0)
		ft_press_a(game);
	else if (code == 1)
		ft_press_s(game);
	else if (code == 2)
		ft_press_d(game);
	return (code);
}

