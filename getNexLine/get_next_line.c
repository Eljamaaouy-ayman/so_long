/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:38:36 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/16 17:40:34 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_rest(char *stock)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (0);
	}
	res = ft_calloc(ft_strlen(stock) - i + 1, 1);
	if (!res)
		return (NULL);
	i++;
	j = 0;
	while (stock[i + j])
	{
		res[j] = stock[i + j];
		j++;
	}
	res[j] = '\0';
	free(stock);
	return (res);
}

char	*ft_line(char *s)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		res = ft_calloc(i + 2, 1);
	else if (s[i] == 0)
		res = ft_calloc(i + 1, 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] && s[i] == '\n')
		res[i] = '\n';
	return (res);
}

char	*join_and_free(char *result, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(result, buffer);
	free(result);
	return (temp);
}

char	*ft_read(int fd, char *stock)
{
	char	*buffer;
	int		bytesread;

	bytesread = 1;
	if (!stock)
		stock = ft_calloc(1, 1);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(buffer);
			free(stock);
			return (NULL);
		}
		buffer[bytesread] = 0;
		stock = join_and_free(stock, buffer);
		if (ft_strchr1(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	stock = ft_read(fd, stock);
	if (!stock)
		return (NULL);
	res = ft_line(stock);
	stock = ft_rest(stock);
	return (res);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("ayman.txt", O_RDWR);
//     char *s = get_next_line(fd);
//     while(s != NULL){
//         printf("%s", s);
//         s = get_next_line(fd);
//     }

//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     char *s = get_next_line(fd);
//     while(s != NULL){
//         printf("%s", s);
//         s = get_next_line(fd);
//     }
// }
