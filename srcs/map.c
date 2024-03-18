/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:55:16 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/03/12 17:59:31 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minas.h"
#include "libft.h"

char	rchar(void)
{
	int	r;

	r = rand() % 10;
	if (r % 2 == 0)
		return ('0');
	else
		return ('M');
}

char	*mallc(int x)
{
	char	*ret;

	ret = ft_calloc (sizeof(char), (x + 1));
	if (!ret)
		return (NULL);
	else
		return (ret);
}

char	**generate_map(void)
{
	int		rx;
	int		ry;
	int		j;
	int		i;
	char	**ret;

	srand(time(NULL));
	rx = rand() % 6 + 6;
	ry = rand() % 6 + 6;
	ret = ft_calloc(ry + 1, sizeof(char *));
	j = 0;
	while (j < ry)
	{
		ret[j] = mallc(rx);
		if (!ret[j])
			return (NULL);
		i = 0;
		while (i < rx)
		{
			ret[j][i] = rchar();
			i++;
		}
		j++;
	}
	return (ret);
}
