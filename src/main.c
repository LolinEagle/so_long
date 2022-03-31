/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:22:45 by frrusso           #+#    #+#             */
/*   Updated: 2022/03/14 11:23:01 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_argc(int ac)
{
	if (ac > 2)
		write(1, "Warning\nOnly the first argument while be used.\n", 47);
}

int	ft_isber(char *av)
{
	int		i;
	int		j;
	char	*ber;

	if (ft_strlen(av) < 4)
		return (write(1, "Not a valid .ber file.\n", 23));
	ber = ".ber";
	i = -1;
	while (av[++i])
	{
		j = 0;
		while (ber[j] && av[i + j] == ber[j])
			j++;
		if (!av[i + j])
			return (0);
	}
	return (write(1, "Not a valid .ber file.\n", 23));
}

int	ft_ismap(t_axe **wh, char ***map, char *av)
{
	*wh = ft_axenew();
	*map = ft_map(av, *wh);
	if (!*map)
	{
		free(*wh);
		return (0);
	}
	return (1);
}

void	*ft_win(void *mlx, t_axe *wh)
{
	int		sizex;
	int		sizey;
	void	*res;

	res = mlx_new_window(mlx, TILE * wh->x, TILE * wh->y, "so_long");
	mlx_get_screen_size(mlx, &sizex, &sizey);
	if (sizex < TILE * wh->x || sizey < TILE * wh->y)
		write(1, "Warning\nYouy map is too big.\n", 29);
	free(wh);
	return (res);
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_axe	*wh;
	char	**map;

	if (ac > 1)
	{
		ft_argc(ac);
		if (ft_isber(av[1]))
			return (1);
		mlx = mlx_init();
		if (!mlx)
			return (1);
		if (!ft_ismap(&wh, &map, av[1]))
			return (ft_free_mlx(mlx));
		win = ft_win(mlx, wh);
		if (!win)
			return (ft_free(mlx, win, map));
		if (ft_mlx_new_image(mlx, win, map))
			return (1);
		return (so_long(mlx, win, map));
	}
	else
		write(1, "Usage : ./so_long <mapfile.ber>\n", 32);
	return (0);
}
