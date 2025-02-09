/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:00:34 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/09 12:56:30 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_outlines(t_game *game)
{
	int (i), (j), (len);
	i = 0;
	j = 0;
	len = ft_strlen(game->map[j]) - 1;
	while (game->map[j] != NULL)
	{
		if (game->map[j][0] != 1 || game->map[j][len] != 1)
			return (-1);
	}
	while (game->map[0][i] != '\n')
	{
		if (game->map[0][i] != 1 || game->map[j][i] != 1)
			return (-1);
	}
	return (0);
}

int	check_length(t_game *game)
{
	size_t (j), (len);
	j = 0;
	len = ft_strlen(game->map[j++]);
	while (game->map[j] != NULL)
	{
		if (ft_strlen(game->map[j++]) != len)
			return (-1);
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
		free(line);
	}
	free(line);
	close(fd);
	return (1);
}

int ft_check(t_game *game)
{
	if (check_length(game->map) == -1)
		return (write(2, "unvalid map, \n", 12), 0);
	if (check_outlines(game->map) == -1)
		return (write(2, "unvalid map, unvalid outlines\n", 30), 0);
	if (count_coins(game->map) < 1)
		return (write(2, "unvalid map, less than a coin\n", 30), 0);
	if (count_exit(game->map) > 1)
		return (write(2, "unvalid map, more than one exit\n", 32), 0);
	if (count_players(game->map) > 1)
		return (write(2, "unvalid map, more than one player\n", 34), 0);
	return (1);
}
int	check_map(t_game *game, char *av)
{
	char	*line;

	*game = (t_game){0};
	int (fd), (x), (y);
	y = 0;
	x = 0;
	if (count_rows(game, av) == -1)
		return (write(1, "unvalid map, misalligned map!\n", 30), 0);
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
		line = get_next_line(fd);
		game->map[y++] = line;
	}
	game->map[y] = NULL;
	ft_check(game);
	return 0;
}

int main(int ac, char **av)
{
	t_game game;
	check_map(&game, av[1]);
}
