/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:08:38 by frrusso           #+#    #+#             */
/*   Updated: 2021/11/26 11:19:42 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (c > 'Z' && c < 'a')
		return (0);
	if (c > '9' && c < 'A')
		return (0);
	if (c >= '0' && c <= 'z')
		return (1);
	else
		return (0);
}
