/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:28:57 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/09 11:32:18 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_players(t_game *game)
{
	int (i), (j);
	j = 0;
	while (game->map[j] != NULL)
	{
		i = 0;
		while (game->map[j][i] != '\n')
		{
			if (game->map[j][i] == 'P')
				game->count_player++;
			i++;
		}
		j++;
	}
	return (game->count_player);
}

int	count_coins(t_game *game)
{
	int (i), (j);
	j = 0;
	while (game->map[j] != NULL)
	{
		i = 0;
		while (game->map[j][i] != '\n')
		{
			if (game->map[j][i] == 'C')
				game->total_coin++;
			i++;
		}
		j++;
	}
	return (game->total_coin);
}

int	count_exit(t_game *game)
{
	int (i), (j);
	j = 0;
	while (game->map[j] != NULL)
	{
		i = 0;
		while (game->map[j][i] != '\n')
		{
			if (game->map[j][i] == 'E')
				game->count_exit++;
			i++;
		}
		j++;
	}
	return (game->count_exit);
}

size_t	ft_strlen2(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}