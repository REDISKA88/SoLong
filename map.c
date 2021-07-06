#include "so_long.h"

int	ft_maplines(char *argv1, t_map *mp)
{
	int		fd;
	int		size;
	char	*line;

	size = 0;
	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		ft_errors(2);
	while (get_next_line(fd, &line) > 0)
	{
		size++;
		free(line);
	}
	free(line);
	close(fd);
	mp->height = size + 1;
	return (mp->height);
}

void ft_create_map2(t_map *mp, char *argv1)
{
	int i;
	int fd;
	char *line;

	i = 0;
	mp->map = malloc(ft_maplines(argv1, mp) * sizeof(char *));
	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		ft_errors(2);
	while (get_next_line(fd, &line) > 0)
	{
		mp->map[i] = line;
		mp->width = ft_stlen(mp->map[i]);
		ft_check_symb(mp, mp->map[i]);
		i++;
	}
	mp->map[i] = line;
	ft_check_symb(mp, mp->map[i]);
	free(line);
	if (!mp->map)
		ft_errors(3);
	check_size(mp);
	ft_check_epc(mp);
	ft_border_checker(mp);
	ft_check_up_bord(mp);
	close(fd);
}