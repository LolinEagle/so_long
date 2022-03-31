/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:49:59 by frrusso           #+#    #+#             */
/*   Updated: 2022/03/23 12:50:12 by frrusso          ###   ########.fr       */
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
	res->pxy = ft_findplayer(map);
	res->img[0] = mlx_xpm_file_to_image(mlx, "assets/sExit.xpm", &nul, &nul);
	if (!img[0])
		return (NULL);
	res->img[1] = mlx_xpm_file_to_image(mlx, "assets/sPlayer.xpm", &nul, &nul);
	res->img[2] = mlx_xpm_file_to_image(mlx, "assets/sTile.xpm", &nul, &nul);
	res->img[3] = mlx_xpm_file_to_image(mlx, "assets/sWall.xpm", &nul, &nul);
	return (res);
}

int	ft_free_mlx(void *mlx)
{
	mlx_destroy_display(mlx);
	free(mlx);
	return (1);
}

int	ft_free(void *mlx, void *win, char **map)
{
	int	i;

	if (map)
	{
		i = -1;
		while (map[++i])
			free(map[i]);
		free(map);
	}
	if (mlx && win)
		mlx_destroy_window(mlx, win);
	if (mlx)
		ft_free_mlx(mlx);
	return (1);
}
