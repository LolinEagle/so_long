/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:53:18 by frrusso           #+#    #+#             */
/*   Updated: 2022/03/21 15:53:27 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_string_put(void *mlx, void *win, char *str)
{
	char	*put;

	put = ft_strjoin("Movement : ", str);
	mlx_string_put(mlx, win, 28 - 1, 36 - 1, 0xFF000000, put);
	mlx_string_put(mlx, win, 28 + 1, 36 - 1, 0xFF000000, put);
	mlx_string_put(mlx, win, 28 - 1, 36 + 1, 0xFF000000, put);
	mlx_string_put(mlx, win, 28 + 1, 36 + 1, 0xFF000000, put);
	mlx_string_put(mlx, win, 28, 36, 0xFFFFFFFF, put);
	free(put);
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

void	ft_put_image(void *mlx, void *win, char **map, void **img)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] && map[i][j] != '\n')
			mlx_put_image_to_window(
				mlx, win, ft_img(map[i][j], img), TILE * j, TILE * i);
	}
}

int	ft_mlx_destroy_image(void *mlx, void **img, int i)
{
	while (i >= 0)
		mlx_destroy_image(mlx, img[i--]);
	return (1);
}

int	ft_mlx_new_image(void *mlx, void *win, char **map)
{
	int		i;
	void	*img[5];

	img[0] = mlx_xpm_file_to_image(mlx, "assets/sExit.xpm", &i, &i);
	if (!img[0])
		return (1);
	img[1] = mlx_xpm_file_to_image(mlx, "assets/sKey.xpm", &i, &i);
	if (!img[1])
		return (ft_mlx_destroy_image(mlx, img, 0));
	img[2] = mlx_xpm_file_to_image(mlx, "assets/sPlayer.xpm", &i, &i);
	if (!img[2])
		return (ft_mlx_destroy_image(mlx, img, 1));
	img[3] = mlx_xpm_file_to_image(mlx, "assets/sTile.xpm", &i, &i);
	if (!img[3])
		return (ft_mlx_destroy_image(mlx, img, 2));
	img[4] = mlx_xpm_file_to_image(mlx, "assets/sWall.xpm", &i, &i);
	if (!img[4])
		return (ft_mlx_destroy_image(mlx, img, 3));
	ft_put_image(mlx, win, map, img);
	ft_mlx_string_put(mlx, win, "0");
	ft_mlx_destroy_image(mlx, img, 4);
	return (0);
}
