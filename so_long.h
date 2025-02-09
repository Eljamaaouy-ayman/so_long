/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:55:41 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/09 11:32:05 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./getNexLine/get_next_line.h"

typedef struct {
    int total_coin;
    int count_exit;
    int count_player;
    char **map;
    int rows;
    int colomns;
} t_game;

int count_exit(t_game *game);
int	count_coins(t_game *game);
int	count_players(t_game *game);
int check_outlines(t_game *game);
int check_length(t_game *game);
int check_map(t_game *game, char *av);
size_t	ft_strlen2(const char *s);
int count_rows(t_game *game, char *av);
