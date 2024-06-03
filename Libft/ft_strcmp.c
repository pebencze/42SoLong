/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:08:25 by pbencze           #+#    #+#             */
/*   Updated: 2024/02/21 17:09:59 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	if ((unsigned char)s1[i] < (unsigned char)s2[i])
		return (-1);
	if ((unsigned char)s1[i] > (unsigned char)s2[i])
		return (1);
	else
		return (0);
}
