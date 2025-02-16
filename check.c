/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:00:34 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/16 20:56:11 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_outlines(t_game *game)
{
	int (i), (j), (len);
	j = 0;
	i = 0;
	len = ft_strlen(game->map[j]) - 1;
	while (game->map[j] != NULL)
	{
		if (game->map[j][0] != '1' || game->map[j][len - 1] != '1')
			return (-1);
		j++;
	}
	while (game->map[0][i] != '\n')
	{
		if (game->map[0][i] != '1' || game->map[j - 1][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int count_rows(t_game *game, char *av)
{
	char	*line;

	int (fd), (x);
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	game->colomns = ft_strlen2(line);
	while (line)
	{
		x = ft_strlen2(line);
		if (x != game->colomns)
			return (-1);
		game->rows++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (1);
}

int ft_check(t_game *game)
{
	if (check_outlines(game) == -1)
		return (write(2, "unvalid map, unvalid outlines\n", 30), exit(0), 0);
	if (other_char(game) == -1)
		return (write(2, "unvalid map, unvalid character\n", 31), exit(0), 0);
	if (count_coins(game) < 1)
		return (write(2, "unvalid map, less than a coin\n", 30), exit(0), 0);
	if (count_exit(game) != 1)
		return (write(2, "unvalid map, must be one exit\n", 30), exit(0), 0);
	if (count_players(game) != 1)
		return (write(2, "unvalid map, must be one player\n", 32), exit(0), 0);
	if (flood_fill(game) == 0)
		return (write(2, "unvalid map, not everything accessible\n", 39), exit(0), 0);
	return (1);
}

int	check_map(t_game *game, char *av)
{
	char	*line;

	*game = (t_game){0};
	int (fd), (y);
	y = 0;
	if (count_rows(game, av) == -1)
		return (write(1, "unvalid map, misalligned map!\n", 30), exit(1), 0);
	game->map = malloc(sizeof(char *) * (game->rows));
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error opening file", 18);
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		game->map[y++] = line;
		line = get_next_line(fd);
	}
	game->map[y] = NULL;
	ft_check(game);
	return 0;
}

int main(int ac, char **av)
{
	if (ac != 2 || check_name(av[1]) == 0)
		return (ft_printf("Error"), 1);
	t_game game;
	check_map(&game, av[1]);
	window(&game);
}
