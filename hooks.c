#include "so_long.h"
int key_hook(int code, t_game *game, t_map *mp)
{
	if (code == 53)
		ft_end_game(game);
	else if (code == 13)
		ft_press_w(game, mp);
	else if (code == 0)
		ft_press_a(game);
	else if (code == 0)
		ft_press_s(game);
	else if (code == 1)
		ft_press_d(game);
	return (code);
}
//void ft_create_hooks()
