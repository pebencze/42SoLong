/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:26:16 by pbencze           #+#    #+#             */
/*   Updated: 2024/03/05 18:51:19 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static char	**free_arr(char **arr1, char **arr2)
{
	int	i;

	i = 0;
	if (arr1)
	{
		while (arr1[i])
			free(arr1[i++]);
		free(arr1);
	}
	i = 0;
	if (arr2)
	{
		while (arr2[i])
			free(arr2[i++]);
		free(arr2);
	}
	return (NULL);
}

static char	**append_arr(char **arr, char *new_str)
{
	ssize_t	i;
	char	**new_arr;

	i = ft_arr_len(arr);
	new_arr = (char **)ft_calloc(sizeof(char *), (i + 2));
	if (!new_arr)
		return (free_arr(arr, NULL));
	i = 0;
	while (arr[i])
	{
		new_arr[i] = ft_strdup(arr[i]);
		if (!new_arr[i])
			return (free_arr(arr, new_arr));
		i++;
	}
	new_arr[i] = ft_strdup(new_str);
	if (!new_arr[i])
		return (free_arr(arr, new_arr));
	free_arr(arr, NULL);
	return (new_arr);
}

static char	**make_matrix(int fd)
{
	char	**arr;
	char	*line;

	arr = (char **)ft_calloc(sizeof(char *), 1);
	if (!arr)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strchr(line, '\n'))
			line[ft_strlen(line) - 1] = '\0';
		arr = append_arr(arr, line);
		free (line);
		if (!arr)
			return (NULL);
	}
	return (arr);
}

void	save_map(t_so_long *game, char *file)
{
	game->fd = open(file, O_RDONLY);
	if (game->fd < 0)
		ft_exit_failure(game, strerror(errno));
	game->map.matrix = make_matrix(game->fd);
	close(game->fd);
	game->fd = -1;
	if (!(game->map.matrix) || !(game->map.matrix[0]))
		ft_exit_failure(game, "Failure on memory allocation");
}
