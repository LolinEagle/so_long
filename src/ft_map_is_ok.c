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

// int	ft_map_is_ok(char **map, int *w, int *h)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	int		ecp[3];
// 	char	*str;

// 	ecp[0] = 0;
// 	ecp[1] = 0;
// 	ecp[2] = 0;
// 	str = "01CEP";
// 	i = -1;
// 	while (map[++i])
// 	{
// 		j = -1;
// 		while (map[i][++j])
// 		{
// 			if ((i == 0 || i == *h || j == 0 || j == *w) && map[i][j] != '1')
// 				return (0);
// 			k = 0;
// 			while (str[k] && map[i][j] != str[k])
// 				k++;
// 			if (!str[k])
// 				return (0);
// 			if (map[i][j] == 'E')
// 				ecp[0]++;
// 			else if (map[i][j] == 'C')
// 				ecp[1]++;
// 			else if (map[i][j] == 'P')
// 				ecp[2]++;
// 		}
// 	}
// 	if (ecp[0] == 0 || ecp[1] == 0 || ecp[2] != 1)
// 		return (0);
// 	return (1);
// }

int	ft_map_is_ok(char **map, int *w, int *h)
{
	if (map && *w && *h)
		return (1);
	return (0);
}
