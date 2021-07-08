#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"

typedef struct s_xpm_p
{
	int		height;
	int		width;
	void	*img;
}				t_xpm_p;

typedef struct s_xpm_e
{
	int		height;
	int		width;
	void	*img;
}				t_xpm_e;

typedef struct s_xpm_c
{
	int		height;
	int		width;
	void	*img;
}				t_xpm_c;

typedef struct s_xpm_w
{
	int		height;
	int		width;
	void	*img;
}				t_xpm_w;

typedef struct s_xpm_g
{
	int		height;
	int		width;
	void	*img;
}				t_xpm_g;

typedef struct s_game
{
	int		i;
	int		j;
	int		pos_x;
	int		pos_y;
	int		count_coins;
	int		p_mov;
	int		map_e;
	int		map_p;
	int		map_c;
	int		width;
	int		height;
	char	**map;
	void	*mlx;
	void	*win;
	t_xpm_c	xpm_coin;
	t_xpm_e	xpm_exit;
	t_xpm_w	xpm_wall;
	t_xpm_g	xpm_grass;
	t_xpm_p	xpm_player;
}				t_game;

int		display2(t_game *game);
void	ft_check_up_down(t_game *game);
void	ft_valid_map(t_game *game);
void	ft_create_xpm_p(t_xpm_p *player, t_game *game);
void	ft_create_xpm_g(t_xpm_g *grass, t_game *game);
void	ft_create_xpm_w(t_xpm_w *wall, t_game *game);
void	ft_create_xpm_c(t_xpm_c *coin, t_game *game);
void	ft_create_xpm_e(t_xpm_e *exit, t_game *game);
void	ft_putnbr_fd(int n, int fd);
void	ft_errors2(int code);
void	ft_put_player_img(t_xpm_p *player, t_game *game, int x, int y);
void	ft_put_grass_img(t_xpm_g *grass, t_game *game, int x, int y);
void	ft_put_wall_img(t_xpm_w *wall, t_xpm_g *grass, t_game *game);
void	ft_put_coin_img(t_xpm_c *coin, t_xpm_g *grass, t_game *game);
void	ft_put_exit_img(t_xpm_e *exit, t_xpm_g *grass, t_game *game);
int		main(int argc, char **argv);
void	ft_errors(int code);
void	ft_init(t_game *game);
void	check_size(t_game *game);
void	ft_check_epc(t_game *game);
void	ft_border_checker(t_game *game);
int		ft_maplines(char *argv1, t_game *game);
void	ft_create_map2(t_game *game, char *argv1);
void	ft_free_array(char **temp);
int		key_hook(int code, t_game *game);
void	ft_start_game(t_game *game);
void	ft_press_w(t_game *game);
void	ft_press_a(t_game *game);
void	ft_press_s(t_game *game);
void	ft_press_d(t_game *game);
int		end_game(t_game *game);
int		str_char(const char *s, char c);
void	ft_putchar(char c);

#endif
