/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:27:16 by pbencze           #+#    #+#             */
/*   Updated: 2024/03/05 18:58:35 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static void	move_left(t_so_long *game)
{
	if (game->map.matrix[game->map.pos_p.x][game->map.pos_p.y - 1] == '1')
		return ;
	game->map.pos_p.y--;
	collect_and_print(game);
}

static void	move_right(t_so_long *game)
{
	if (game->map.matrix[game->map.pos_p.x][game->map.pos_p.y + 1] == '1')
		return ;
	game->map.pos_p.y++;
	collect_and_print(game);
}

static void	move_up(t_so_long *game)
{
	if (game->map.matrix[game->map.pos_p.x - 1][game->map.pos_p.y] == '1')
		return ;
	game->map.pos_p.x--;
	collect_and_print(game);
}

static void	move_down(t_so_long *game)
{
	if (game->map.matrix[game->map.pos_p.x + 1][game->map.pos_p.y] == '1')
		return ;
	game->map.pos_p.x++;
	collect_and_print(game);
}

int	handle_key(int keycode, t_so_long *game)
{
	if (keycode == 65307)
		ft_exit_success(game);
	else if (keycode == 65361)
		move_left(game);
	else if (keycode == 65362)
		move_up(game);
	else if (keycode == 65363)
		move_right(game);
	else if (keycode == 65364)
		move_down(game);
	if (game->map.pos_p.x == game->map.pos_e.x
		&& game->map.pos_p.y == game->map.pos_e.y)
	{
		if (game->collected == game->map.num_c)
		{
			ft_putstr_fd("\nCongratulations, you won!", 1);
			ft_exit_success(game);
		}
		else
			ft_putstr_fd("\nYou need to collect all collectables!\n", 1);
	}
	return (0);
}
