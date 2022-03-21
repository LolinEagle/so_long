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

int	ft_deal_key(int key, void *param)
{
	(void)param;
	ft_putchar_fd(key, 1);
	return (0);
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

// mlx_expose_hook(win, , );
// mlx_loop_hook(mlx, , );
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
		if (!mlx || !ft_isber(av[1]))
			return (1);
		map = ft_map(av[1], &w, &h);
		if (!map)
			return (1);
		win = mlx_new_window(mlx, TILE * w, TILE * h, av[0] + 2);
		ft_mlx_new_image(mlx, win, map);
		mlx_string_put(mlx, win, 16, 16, 0x00FFFFFF, "TEST");
		mlx_key_hook(win, ft_deal_key, NULL);
		mlx_loop(mlx);
		ft_free(&mlx, &win, &map);
	}
	return (0);
}
