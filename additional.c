/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:04:40 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/16 18:41:05 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int img_to_ptr(t_game *game)
{
    int (w), (h);
    game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w, &h);
    game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
    game->player = mlx_xpm_file_to_image(game->mlx, "textures/player1.xpm", &w, &h);
    game->coin = mlx_xpm_file_to_image(game->mlx, "textures/coin3.xpm", &w, &h);
    game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit1.xpm", &w, &h);
    if (!game->floor || !game->wall || !game->player || !game->coin || !game->exit)
        return (0);
    return (1);
}
