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

int	ft_isber(char *av)
{
	int		i;
	int		j;
	char	*ber;

	if (ft_strlen(av) < 4)
		return (1);
	ber = ".ber";
	i = -1;
	while (av[++i])
	{
		j = 0;
		while (ber[j] && av[i + j] == ber[j])
			j++;
		if (!av[i + j])
			return (1);
	}
	return (0);
}

void	*ft_img(char c, void **img)
{
	if (c == 'E')
		return (img[0]);
	else if (c == 'C')
		return (img[1]);
	else if (c == 'P')
		return (img[2]);
	else if (c == '0')
		return (img[3]);
	else
		return (img[4]);
}

void	ft_mlx_new_image(void *mlx, void *win, char **map)
{
	int		i;
	int		j;
	int		w;
	int		h;
	void	*img[5];

	img[0] = mlx_xpm_file_to_image(mlx, "assets/sExit.xpm", &w, &h);
	img[1] = mlx_xpm_file_to_image(mlx, "assets/sKey.xpm", &w, &h);
	img[2] = mlx_xpm_file_to_image(mlx, "assets/sPlayer.xpm", &w, &h);
	img[3] = mlx_xpm_file_to_image(mlx, "assets/sTile.xpm", &w, &h);
	img[4] = mlx_xpm_file_to_image(mlx, "assets/sWall.xpm", &w, &h);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] && map[i][j] != '\n')
			mlx_put_image_to_window(mlx, win, ft_img(map[i][j], img), TILE * j, TILE * i);
	}
}

void	ft_free(void **mlx, void **win, char ***map)
{
	int	i;

	i = -1;
	while (*map[++i])
		free(*map[i]);
	free(*map);
	mlx_destroy_window(*mlx, *win);
}

int	main(int ac, char **av)
{
	int		w;
	int		h;
	void	*mlx;
	void	*win;
	char	**map;

	if (ac > 1)
	{
		mlx = mlx_init();
		if (!mlx)
			return (1);
		if (!ft_isber(av[1]))
			return (0);
		map = ft_map(av[1], &w, &h);
		win = mlx_new_window(mlx, TILE * w, TILE * h, av[0] + 2);
		ft_mlx_new_image(mlx, win, map);
		mlx_string_put(mlx, win, 16, 16, 0x00FFFFFF, "TEST");
		mlx_loop(mlx);
		ft_free(&mlx, &win, &map);
	}
	return (0);
}
