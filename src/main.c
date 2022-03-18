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
	i = 0;
	while (av[i])
	{
		j = 0;
		while (ber[j] && av[i + j] == ber[j])
			j++;
		if (!av[i + j])
			return (1);
		i++;
	}
	return (0);
}

void	ft_mlx_new_image(void *mlx, void *win, char **map)
{
	int		i;
	int		j;
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, "./assets/sWall.xpm", &w, &h);
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			mlx_put_image_to_window(mlx, win, img, TILE * i, TILE * j);
			i++;
		}
		j++;
	}
}

void	ft_free(char ***map)
{
	int	i;

	i = 0;
	while (*map[i])
	{
		free(*map[i]);
		i++;
	}
	free(*map);
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
		mlx_destroy_window(mlx, win);
		ft_free(&map);
	}
	return (0);
}
