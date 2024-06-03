/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:57:24 by pbencze           #+#    #+#             */
/*   Updated: 2024/03/05 19:54:34 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

ssize_t	ft_arr_len(char **arr)
{
	ssize_t	i;

	i = 0;
	if (!arr)
		return (-1);
	while (arr[i])
		i++;
	return (i);
}
