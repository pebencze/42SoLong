/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:09:48 by pbencze           #+#    #+#             */
/*   Updated: 2024/02/02 17:50:01 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*trav;

	if (!lst)
		return (NULL);
	trav = lst;
	while (trav->next)
		trav = trav->next;
	return (trav);
}
