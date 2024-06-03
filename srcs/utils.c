/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:24:44 by pbencze           #+#    #+#             */
/*   Updated: 2024/03/06 14:21:35 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	collect_and_print(t_so_long *game)
{
	char	*str;
	char	*s2;
	int		i;

	i = -1;
	while (++i < game->map.num_c)
	{
		if (game->map.pos_p.y == game->map.pos_c[i].y
			&& game->map.pos_p.x == game->map.pos_c[i].x)
		{
			game->map.pos_c[i] = (t_points){-1, -1};
			game->collected++;
		}
	}
	put_images(game);
	game->moves++;
	s2 = ft_itoa(game->moves);
	str = ft_strjoin("\rMoves: ", s2);
	free(s2);
	if (str == NULL)
		ft_exit_failure(game, "Failure on displaying moves");
	mlx_string_put(game->win.mlx_ptr, game->win.win_ptr,
		25, 30, 16731904, str + 1);
	ft_putstr_fd(str, 1);
	free(str);
}
