/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:53:05 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/07 15:59:26 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;
	int		j;

	i = 0;
	if (!str || str[0] ==  '\0')
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

	reader = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	*buff = '\0';
	if (!buff)
		return (NULL);
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
	int		len_memory;
	int		len_line;

	if (memory == NULL || line == NULL)
		return (NULL);
	len_memory = ft_strlen(memory);
	len_line = ft_strlen(line);
	if (len_line == 0)
	{
		free(memory);
		return (NULL);
	}
	new = malloc(len_memory - len_line + 1);
	ft_memcpy(new, memory + len_line, len_memory - len_line + 1);
	free(memory);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*memory;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	memory = ft_buff_to_memory(fd, memory);
	if (!memory)
		return (NULL);
	line = ft_get_line(memory);
	if (!line)
		return (NULL);
	memory = ft_reset_memory(memory, line);
	return (line);
}
