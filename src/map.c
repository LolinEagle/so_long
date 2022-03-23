/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:48:32 by frrusso           #+#    #+#             */
/*   Updated: 2022/03/15 16:48:39 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mapsize(char *file)
{
	int		i;
	int		fd;
	char	*gnl;

	i = 0;
	fd = open(file, O_RDONLY);
	gnl = get_next_line(fd);
	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(fd);
		i++;
	}
	close(fd);
	free(gnl);
	return (i);
}

int	ft_strlen_gnl(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	**ft_file(int fd)
{
	close(fd);
	write(1, "Error\nYour map doesn't exist\n", 29);
	return (NULL);
}

char	**ft_free_map(int i, int fd, char **map)
{
	while (i >= 0)
		free(map[i--]);
	free(map);
	close(fd);
	write(1, "Error\nYour map doesn't respect the rules set\n", 45);
	return (NULL);
}

char	**ft_map(char *av, t_axe *wh)
{
	int		i;
	int		fd;
	char	**res;

	fd = open(av, O_RDONLY);
	if (read(fd, NULL, 0) < 0)
		return (ft_file(fd));
	wh->y = ft_mapsize(av);
	res = malloc(sizeof(char *) * (wh->y + 1));
	res[0] = get_next_line(fd);
	wh->x = ft_strlen_gnl(res[0]);
	i = 0;
	while (res[i])
	{
		i++;
		res[i] = get_next_line(fd);
		if (i < wh->y && ft_strlen_gnl(res[i]) != wh->x)
			return (ft_free_map(i, fd, res));
	}
	if (!ft_map_is_ok(res, wh))
		return (ft_free_map(i - 1, fd, res));
	close(fd);
	return (res);
}
