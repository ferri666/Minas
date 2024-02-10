/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:37:20 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/02/04 12:37:29 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minas.h"
#include "libft.h"

void	dmap_error(char	**map, char *str)
{
	ft_putstr_fd(str, 2);
	ft_free_matrix((void **)map);
	exit(-1);
}
