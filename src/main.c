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

	ber = ".ber";
	i = 0;
	while (av[i] && av[i] != '.')
		i++;
	j = 0;
	while (ber[j] && av[i + j] == ber[j])
		j++;
	if (!av[i + j] && ft_strlen(av) > 4)
		return (1);
	return (0);
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
	int		x;
	int		y;
	char	**map;
	void	*mlx;
	void	*win;

	if (ac > 1)
	{
		mlx = mlx_init();
		if (!mlx)
			return (1);
		if (!ft_isber(av[1]))
			return (0);
		map = ft_map(av[1], &x, &y);
		win = mlx_new_window(mlx, TILE * x, TILE * y, av[0] + 2);
		mlx_loop(mlx);
		mlx_destroy_window(mlx, win);
		ft_free(&map);
	}
	return (0);
}
