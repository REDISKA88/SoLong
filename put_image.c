#include "so_long.h"
void	ft_put_player_img(t_xpm_p *player, t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, player->img, x * 32, y * 32);
}

void	ft_put_grass_img(t_xpm_g *grass, t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, grass->img, x * 32, y * 32);
}

void	ft_put_wall_img(t_xpm_w *wall, t_xpm_g *grass, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, grass->img, game->j * 32,
		game->i * 32);
	mlx_put_image_to_window(game->mlx, game->win, wall->img, game->j * 32,
		game->i * 32);
}

void	ft_put_coin_img(t_xpm_c *coin, t_xpm_g *grass, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, grass->img, game->j * 32,
		game->i * 32);
	mlx_put_image_to_window(game->mlx, game->win, coin->img, game->j * 32,
		game->i * 32);
}

void	ft_put_exit_img(t_xpm_e *exit, t_xpm_g *grass, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, grass->img, game->j * 32,
		game->i * 32);
	mlx_put_image_to_window(game->mlx, game->win, exit->img, game->j * 32,
		game->i * 32);
}
