#include "so_long.h"
void	ft_start_game(t_game *game)
{
	game->mlx = mlx_init();
	ft_create_xpm_p(&game->xpm_player, game);
	ft_create_xpm_w(&game->xpm_wall, game);
	ft_create_xpm_c(&game->xpm_coin, game);
	ft_create_xpm_g(&game->xpm_grass, game);
	ft_create_xpm_e(&game->xpm_exit, game);
	game->win = mlx_new_window(game->mlx, game->width * 32,
			game->height *32, "SO_LONG");
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 33, 1L << 5, end_game, game);
	game->count_coins = 0;
	game->p_mov = 0;
	mlx_loop_hook(game->mlx, display2, game);
	mlx_loop(game->mlx);
}

int	display2(t_game *game)
{
	game->i = 0;
	while (game->i < game->height)
	{
		game->j = 0;
		while (game->j < game->width)
		{
			if (game->map[game->i][game->j] == '1')
				ft_put_wall_img(&game->xpm_wall, &game->xpm_grass, game);
			else if (game->map[game->i][game->j] == '0')
				ft_put_grass_img(&game->xpm_grass, game, game->j, game->i);
			else if (game->map[game->i][game->j] == 'E')
				ft_put_exit_img(&game->xpm_exit, &game->xpm_grass, game);
			else if (game->map[game->i][game->j] == 'C')
				ft_put_coin_img(&game->xpm_coin, &game->xpm_grass, game);
			ft_put_player_img(&game->xpm_player, game, game->pos_x,
				game->pos_y);
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
