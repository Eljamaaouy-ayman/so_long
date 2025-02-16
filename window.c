/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:23:02 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/16 22:03:07 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_win()
{
    exit(0);
    return (0);
}

void draw_map(t_game *game, int i, int j)
{
    if(!game->mlx || !game->win || !game->floor)
        return (printf("hhh"), exit(0));
    if (game->map[i][j] == '0')
        mlx_put_image_to_window(game->mlx, game->win, game->floor, j * 64, i * 64);
    else if(game->map[i][j] == '1')
        mlx_put_image_to_window(game->mlx, game->win, game->wall, j * 64, i * 64);
    else if(game->map[i][j] == 'E')
        mlx_put_image_to_window(game->mlx, game->win, game->exit, j * 64, i * 64);
    else if(game->map[i][j] == 'C')
        mlx_put_image_to_window(game->mlx, game->win, game->coin, j * 64, i * 64);
    else if(game->map[i][j] == 'P')
        mlx_put_image_to_window(game->mlx, game->win, game->player, j * 64, i * 64);
}

void make_map(t_game *game)
{
    int (i), (j);
    i = 0;
    while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            draw_map(game, i, j);
            j++;
        }
        i++;
    }
}

void move_player(t_game *game, int x_move, int y_move)
{
    int (x), (y);
    x = game->x + x_move;
    y = game->y + y_move;
    // if (y < 0 || y >= game->rows) {
    //     printf("%d.\n", y);
    //     return;
    // }
    if (game->map[x][y] == '1')
        return;
    else if (game->map[x][y] == 'C')
    {
        game->collectible--;
        game->map[x][y] = '0';
    }
    else if (game->map[x][y] == 'E')
    {
        if (game->collectible == 0)
            return (ft_printf("you win\n"), exit(0));
        else
            return ;
    }
    game->map[game->x][game->y] = '0';
    game->y = y;
    game->x = x;
    game->map[x][y] = 'P';
    make_map(game);
}
int pressed(int key_code, t_game *game)
{
    (void)game;
    if (key_code == XK_Escape)
    {
        exit(0);
    }
    else if (key_code == XK_w || key_code == XK_Up)
        move_player(game, -1, 0);
    else if (key_code == XK_s || key_code == XK_Down)
        move_player(game, 1, 0);
    else if (key_code == XK_a || key_code == XK_Left)
        move_player(game, 0, -1);
    else if (key_code == XK_d || key_code == XK_Right)
        move_player(game, 0, 1);
    return (1);
}

void    delay(t_game *data)
{
    data->frame_delay++;
    if (data->frame_delay == 100)
    {
        data->current_frame = (data->current_frame + 1) % 4;
        data->frame_delay = 0;
    }
}

int    render_map(t_game *data)
{
    size_t    x;
    size_t    y;

    data->current_frame = (data->current_frame + 1) % 4;


    delay(data);
    y = 0;
    while (y < data->y)
    {
        x = 0;
        while (x < data->x)
        {
            put_image_to_window(data, x, y);
            x++;
        }
        y++;
    }
    return (0);
}


int window(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        return (0);
    game->win = mlx_new_window(game->mlx, game->colomns * 64, game->rows * 64, "so_long");
    if (!game->win)
        return (0);
    if(!img_to_ptr(game))
        return (0);
    make_map(game);
    mlx_loop_hook(game->mlx, render_map, &data);
    mlx_hook(game->win, KeyPress, KeyPressMask, &pressed, game);
    mlx_hook(game->win, 17, 0, &close_win, game);
    mlx_loop(game->mlx);
    return 0;
}