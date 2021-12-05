/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:53:05 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/03 16:11:36 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;
	int		j;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	j = i;
	i = -1;
	while (++i < j)
		line[i] = str[i];
	line[i] = '\0';
	return (line);
}

char	*ft_buff_to_memory(int fd, char *memory)
{
	char	*buff;
	int		reader;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	reader = 1;
	while (!ft_strchr(buff, '\n') && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			free(memory);
			return (NULL);
		}
		buff[reader] = '\0';
		memory = ft_strjoin(memory, buff);
	}	
	free(buff);
	return (memory);
}

char	*ft_reset_memory(char *memory, char *line)
{
	char	*new;
	int		memory_size;
	int		line_size;

	if (memory == NULL || line == NULL)
		return (NULL);
	memory_size = ft_strlen(memory);
	line_size = ft_strlen(line);
	if (line_size <= 0)
	{
		free(memory);
		return (NULL);
	}
	new = malloc(memory_size - line_size + 1);
	ft_memcpy(new, memory + line_size, memory_size - line_size + 1);
	free(memory);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	save = ft_buff_to_memory(fd, save);
	if (!save)
		return (0);
	line = ft_get_line(save);
	save = ft_reset_memory(save, line);
	return (line);
}

int	main(int argc, char const *argv[])
{
	int fd = open("file", O_RDONLY);
	int i = 100;
	char *li;
	while(i--)
	{
		li = get_next_line(fd);
		printf("%s",li);
	}
}
