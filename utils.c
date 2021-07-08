#include "so_long.h"
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	str_char(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	lnum;
	char	res;

	lnum = n;
	if (n < 0)
	{
		ft_putchar('-');
		lnum = lnum * -1;
	}
	if (lnum / 10 != 0)
		ft_putnbr_fd(lnum / 10, fd);
	res = (lnum % 10) + 48;
	ft_putchar(res);
}
