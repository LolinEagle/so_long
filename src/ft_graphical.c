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
	mlx_string_put(mlx, win, 28 - 1, 36 - 1, 0xFF000000, str);
	mlx_string_put(mlx, win, 28 + 1, 36 - 1, 0xFF000000, str);
	mlx_string_put(mlx, win, 28 - 1, 36 + 1, 0xFF000000, str);
	mlx_string_put(mlx, win, 28 + 1, 36 + 1, 0xFF000000, str);
	mlx_string_put(mlx, win, 28, 36, 0xFFFFFFFF, str);
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

int	ft_mlx_new_image(void *mlx, void *win, char **map)
{
	int		i;
	int		j;
	int		w;
	int		h;
	void	*img[5];

	img[0] = mlx_xpm_file_to_image(mlx, "assets/sExit.xpm", &w, &h);
	if (!img[0])
		return (1);
	// img[1] = mlx_xpm_file_to_image(mlx, "assets/sKey.xpm", &w, &h);
	// img[2] = mlx_xpm_file_to_image(mlx, "assets/sPlayer.xpm", &w, &h);
	// img[3] = mlx_xpm_file_to_image(mlx, "assets/sTile.xpm", &w, &h);
	// img[4] = mlx_xpm_file_to_image(mlx, "assets/sWall.xpm", &w, &h);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] && map[i][j] != '\n')
			mlx_put_image_to_window(
				mlx, win, ft_img(map[i][j], img), TILE * j, TILE * i);
	}
	ft_mlx_string_put(mlx, win, "0");
	i = 4;
	while (i >= 0)
		mlx_destroy_image(mlx, img[i--]);
	return (0);
}
