#include "so_long.h"
void ft_check_symb(t_map *mp, char *mapi)
{
	int c;

	c = 0;
	while (mapi[c])
	{
		if (str_char("01CEP", mapi[c]) == 0)
		{
			write(1, "symb valid error\n", 17);
			exit(1);
		}
		ft_count_epc(mapi[c],mp);
		c++;
	}
}

void	check_size(t_map *mp)
{
	int i;
	int width;

	i = 0;
	mp->width = ft_stlen(mp->map[i]);
	i++;
	while (i < mp->height)
	{
		if (ft_stlen(mp->map[i]) != mp->width)
		{
			write(1, "invalid size map", 16);
			exit(1);
		}
		i++;
	}
}

void	ft_count_epc(char map, t_map *mp)
{
	if (map == 'E')
		mp->map_e = mp->map_e + 1;
	if (map == 'P')
		mp->map_p = mp->map_p + 1;
	if (map == 'C')
		mp->map_c = mp->map_c + 1;
}

void	ft_check_epc(t_map *mp)
{
	if (mp->map_p != 1)
	{
		write(1, "player must be One", 18);
		ft_free_array(mp->map);
		exit(1);
	}
	if (mp->map_e  < 1)
	{
		write(1, "Portal Gde", 10);
		ft_free_array(mp->map);
		exit(1);
	}
	if (mp->map_c < 1)
	{
		write(1, "gde money", 9);
		ft_free_array(mp->map);
		exit(1);
	}
}

void	ft_border_checker(t_map *mp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < mp->height)
	{
		if (mp->map[i][0] == '1' && mp->map[i][ft_stlen(mp->map[i]) - 1] == '1')
			i++;
		else
			ft_errors(4);
	}
	i = 0;
	while (mp->map[i][j] != '\0')
	{
		if (mp->map[i][j] != '1')
			ft_errors(5);
		j++;
	}
	write(1, "borders ok", 10);

}
void ft_check_up_bord(t_map *mp)
{
	int i;
	int j;

	i = mp->height;
	j = 0;
	while (mp->map[i][j])
	{
		if (mp->map[i][j] != '1')
			ft_errors(5);
		j++;
	}
	write(1, "down border ok", 14);
}
