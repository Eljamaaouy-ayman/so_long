/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:23:02 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/16 10:57:14 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_win()
{
    exit(0);
    return (0);
}

// int pressed()
// {
    
// } 

int window(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        return (0);
    game->win = mlx_new_window(game->mlx, game->colomns * 64, game->rows * 64, "so_long");
    if (!game->win)
        return (0);
    // mlx_hook(game->win, KeyPress, KeyPressMask, &pressed, game);
    mlx_hook(game->win, 17, 0, &close_win, game);
    mlx_loop(game->mlx);
    return 0;
}