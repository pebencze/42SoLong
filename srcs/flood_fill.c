/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:41:00 by pbencze           #+#    #+#             */
/*   Updated: 2024/03/05 18:51:19 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static void	flood_fill(t_points coords, t_so_long *game)
{
	if (game->map.matrix[coords.x][coords.y] == '1'
		|| game->map.matrix[coords.x][coords.y] == 'F'
		|| coords.x > game->map.height || coords.x < 0
		|| coords.y > game->map.width || coords.y < 0)
		return ;
	else
	{
		game->map.matrix[coords.x][coords.y] = 'F';
		flood_fill((t_points){coords.x + 1, coords.y}, game);
		flood_fill((t_points){coords.x - 1, coords.y}, game);
		flood_fill((t_points){coords.x, coords.y + 1}, game);
		flood_fill((t_points){coords.x, coords.y - 1}, game);
	}
}

void	do_flood_fill(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	flood_fill(game->map.pos_e, game);
	while (game->map.matrix[i])
	{
		j = 0;
		while (game->map.matrix[i][j])
		{
			if (game->map.matrix[i][j] != 'F'
				&& game->map.matrix[i][j] != '1')
				ft_exit_failure(game, "Invalid path");
			j++;
		}
		i++;
	}
}
