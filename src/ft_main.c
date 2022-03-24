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

int	ft_free_mlx(void *mlx)
{
	mlx_destroy_display(mlx);
	free(mlx);
	return (1);
}

void	ft_free(void *mlx, void *win, char **map)
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
	{
		mlx_destroy_window(mlx, win);
		ft_free_mlx(mlx);
	}
}
