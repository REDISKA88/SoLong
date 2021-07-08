#include "so_long.h"
void	ft_create_xpm(t_game *game)
{
	game->xpm_player.img = mlx_xpm_file_to_image(game->mlx, "./player.xpm",
										&game->xpm_player.width,
										&game->xpm_player.height);
	game->xpm_grass.img = mlx_xpm_file_to_image(game->mlx, "./grass.xpm",
												 &game->xpm_grass.width,
												 &game->xpm_grass.height);
	game->xpm_wall.img = mlx_xpm_file_to_image(game->mlx, "./wall.xpm",
												 &game->xpm_wall.width,
												 &game->xpm_wall.height);
	game->xpm_coin.img = mlx_xpm_file_to_image(game->mlx, "./coins.xpm",
												 &game->xpm_coin.width,
												 &game->xpm_coin.height);
	game->xpm_exit.img = mlx_xpm_file_to_image(game->mlx, "./exit.xpm",
												 &game->xpm_exit.width,
												 &game->xpm_exit.height);
}

void	ft_create_xpm_p(t_xpm_p *player, t_game *game)
{
	player->img = mlx_xpm_file_to_image(game->mlx, "./player.xpm",
									   &player->width, &player->height);
}

void	ft_create_xpm_g(t_xpm_g *grass, t_game *game)
{
	grass->img = mlx_xpm_file_to_image(game->mlx, "./grass.xpm",
									   &grass->width, &grass->height);
}

void	ft_create_xpm_w(t_xpm_w *wall, t_game *game)
{
	wall->img = mlx_xpm_file_to_image(game->mlx, "./wall.xpm", &wall->width,
									  &wall->height);
}

void	ft_create_xpm_c(t_xpm_c *coin, t_game *game)
{
	coin->img = mlx_xpm_file_to_image(game->mlx, "./coin.xpm", &coin->width,
									  &coin->height);
}

void	ft_create_xpm_e(t_xpm_e *exit, t_game *game)
{
	exit->img = mlx_xpm_file_to_image(game->mlx, "./exit.xpm", &exit->width,
									  &exit->height);
}