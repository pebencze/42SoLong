/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:44:42 by pbencze           #+#    #+#             */
/*   Updated: 2024/03/05 18:53:02 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static void	measure_map(t_so_long *game)
{
	int		rows;
	int		cols;

	rows = 0;
	cols = ft_strlen(*(game->map.matrix));
	while (game->map.matrix[rows])
	{
		if (ft_strlen(game->map.matrix[rows]) != (size_t)cols)
			ft_exit_failure(game, "Non-rectangular map");
		rows++;
	}
	if (cols < 5 || rows < 3)
		ft_exit_failure(game, "Map too small or empty");
	game->map.height = rows;
	game->map.width = cols;
}

static void	check_and_count(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if ((i == 0 || i == (game->map.height - 1)
					|| j == 0 || j == (game->map.width - 1))
				&& (game->map.matrix[i][j] != '1'))
				ft_exit_failure(game, "Missing walls");
			else if (game->map.matrix[i][j] == 'C')
				game->map.num_c++;
			else if (game->map.matrix[i][j] == 'E')
				game->map.num_e++;
			else if (game->map.matrix[i][j] == 'P')
				game->map.num_p++;
			else if (!(ft_strchr("01", game->map.matrix[i][j])))
				ft_exit_failure(game, "Invalid character in map");
			j++;
		}
		i++;
	}
}

static void	get_pos_pce(t_so_long *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.matrix[i][j] == 'E')
				game->map.pos_e = (t_points){i, j};
			else if (game->map.matrix[i][j] == 'P')
				game->map.pos_p = (t_points){i, j};
			else if (game->map.matrix[i][j] == 'C')
			{
				game->map.pos_c[k] = (t_points){i, j};
				k++;
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_so_long *game)
{
	measure_map(game);
	check_and_count(game);
	game->map.pos_c = (t_points *)ft_calloc(game->map.num_c, sizeof(t_points));
	if (!game->map.pos_c)
		ft_exit_failure(game, "Failure on memory allocation");
	if (game->map.num_c < 1 || game->map.num_e != 1 || game->map.num_p != 1)
		ft_exit_failure(game, "Incorrect amount of 'P' 'C' or 'E' in map");
	get_pos_pce(game);
	do_flood_fill(game);
}
