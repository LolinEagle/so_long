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

void	ft_free(void **mlx, void **win, char ***map, t_axe *wh)
{
	int	i;

	i = -1;
	while (*map[++i])
		free(*map[i]);
	free(*map);
	mlx_destroy_window(*mlx, *win);
	free(wh);
}

int	main(int ac, char **av)
{
	t_axe	*wh;
	void	*mlx;
	void	*win;
	char	**map;

	if (ac > 1)
	{
		mlx = mlx_init();
		if (!mlx || !ft_isber(av[1]))
			return (1);
		wh = ft_axenew();
		map = ft_map(av[1], wh);
		if (!map || wh->x + wh->y < 8)
		{
			free(wh);
			return (1);
		}
		win = mlx_new_window(mlx, TILE * wh->x, TILE * wh->y, av[0] + 2);
		ft_mlx_new_image(mlx, win, map);
		mlx_string_put(mlx, win, 16, 16, 0x00FFFFFF, "TEST");
		so_long(mlx, win);
		ft_free(&mlx, &win, &map, wh);
	}
	return (0);
}
