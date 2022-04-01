/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_is_ok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:57:11 by frrusso           #+#    #+#             */
/*   Updated: 2022/03/21 17:57:16 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_wall(int i, int j, t_axe *wh, char c)
{
	if ((i == 0 || i == wh->y - 1 || j == 0 || j == wh->x - 1) && c != '1')
		return (0);
	return (1);
}

int	ft_traits(char c)
{
	int		k;
	char	*str;

	str = "01ECPX";
	k = 0;
	while (str[k] && c != str[k])
		k++;
	if (!str[k])
		return (0);
	return (1);
}

void	ft_at_less(t_axe *ecp, int *enemy, char c)
{
	if (c == 'E')
		ecp->x++;
	else if (c == 'C')
		ecp->y++;
	else if (c == 'P')
		ecp->z++;
	else if (c == 'X')
		enemy++;
}

int	ft_free_ecp(t_axe *ecp)
{
	free(ecp);
	return (0);
}

int	ft_map_is_ok(char **map, t_axe *wh)
{
	int		i;
	int		j;
	int		enemy;
	t_axe	*ecp;

	enemy = 0;
	ecp = ft_axenew();
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] && map[i][j] != '\n')
		{
			if (!ft_wall(i, j, wh, map[i][j]) || !ft_traits(map[i][j]))
				return (ft_free_ecp(ecp));
			ft_at_less(ecp, &enemy, map[i][j]);
		}
	}
	if (ecp->x == 0 || ecp->y == 0 || ecp->z != 1 || enemy > 1)
		return (ft_free_ecp(ecp));
	free(ecp);
	return (1);
}
