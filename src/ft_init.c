/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:15:31 by frrusso           #+#    #+#             */
/*   Updated: 2022/04/01 15:15:35 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_axe	*ft_axenew(void)
{
	t_axe	*res;

	res = malloc(sizeof(t_axe));
	if (!res)
		return (NULL);
	res->x = 0;
	res->y = 0;
	res->z = 0;
	return (res);
}

int	*ft_findplayer(char **map)
{
	int	i;
	int	j;
	int	*res;

	res = malloc(sizeof(int) * 3);
	if (!res)
		return (NULL);
	res[2] = 0;
	i = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][++j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'C')
				res[2]++;
			if (map[i][j] == 'P')
			{
				res[1] = i;
				res[0] = j;
			}
		}
	}
	return (res);
}

void	*ft_mlx_destroy_image_ptr(void *mlx, void **img, t_mlx *res, int i)
{
	while (i >= 0)
		mlx_destroy_image(mlx, img[i--]);
	free(res);
	return (NULL);
}

t_mlx	*ft_mlxnew(void *mlx, void *win, char **map)
{
	t_mlx	*res;
	int		nul;

	res = malloc(sizeof(t_mlx));
	if (!res)
		return (NULL);
	res->mlx = mlx;
	res->win = win;
	res->map = map;
	res->img[0] = mlx_xpm_file_to_image(mlx, "assets/sExit.xpm", &nul, &nul);
	if (!res->img[0])
		return (ft_mlx_destroy_image_ptr(mlx, res->img, res, -1));
	res->img[1] = mlx_xpm_file_to_image(mlx, "assets/sPlayer.xpm", &nul, &nul);
	if (!res->img[1])
		return (ft_mlx_destroy_image_ptr(mlx, res->img, res, 0));
	res->img[2] = mlx_xpm_file_to_image(mlx, "assets/sTile.xpm", &nul, &nul);
	if (!res->img[2])
		return (ft_mlx_destroy_image_ptr(mlx, res->img, res, 1));
	res->img[3] = mlx_xpm_file_to_image(mlx, "assets/sWall.xpm", &nul, &nul);
	if (!res->img[3])
		return (ft_mlx_destroy_image_ptr(mlx, res->img, res, 2));
	res->pxy = ft_findplayer(map);
	if (!res->pxy)
		return (ft_mlx_destroy_image_ptr(mlx, res->img, res, 3));
	return (res);
}
