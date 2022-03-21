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
	while (s[i])
		i++;
	if (s[i - 1] == '\n')
		return (i - 1);
	return (i);
}

void	*ft_free_map(int i, int fd, char ***map)
{
	while (i >= 0)
		free(*map[i--]);
	free(*map);
	close(fd);
	return (NULL);
}

char	**ft_map(char *av, int *w, int *h)
{
	int		i;
	int		fd;
	char	**res;

	*h = ft_mapsize(av);
	res = malloc(sizeof(char *) * (*h + 1));
	fd = open(av, O_RDONLY);
	res[0] = get_next_line(fd);
	*w = ft_strlen_gnl(res[0]);
	i = 0;
	while (res[i])
	{
		i++;
		res[i] = get_next_line(fd);
		if (i < *h && ft_strlen_gnl(res[i]) != *w)
			return (ft_free_map(i, fd, &res));
	}
	if (!ft_map_is_ok(res, w, h))
		return (ft_free_map(i - 1, fd, &res));
	close(fd);
	return (res);
}
