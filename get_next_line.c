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

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char) c)
	{
		if (*str == '\0' && (char) c != '\0')
			return (NULL);
		str++;
	}
	return ((char *) str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*dest;
	size_t			i;

	source = (unsigned char *) src;
	dest = (unsigned char *) dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (n == 0)
		return (dst);
	while (n--)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*s3;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	s3 = malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	ft_memcpy(s3, s1, lens1);
	ft_memcpy(s3 + lens1, s2, lens2);
	s3[lens1 + lens2] = '\0';
	free(s1);
	return (s3);
}

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


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char	*ft_new(char *str)
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
	free(str);
	return (line);
}

char	*ft_buff_to_save(int fd, char *save)
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
			return (NULL);
		}
		buff[reader] = '\0';
		save = ft_strjoin(save, buff);
	}	
	free(buff);
	return (save);
}

char *get_next_line(int fd)
{
	char *line;
	static char *save;
	
	save = ft_buff_to_save(fd, save);
	if (!save)
		return (0);
	line = ft_get_line(save);
	save = ft_new(save);
	return (line);
}

int main(int argc, char const *argv[])
{
	int fd = open("file", O_RDONLY);
	int i = 5;
	char *li;
	while(i--)
	{
		li = get_next_line(fd);
		printf("%s",li);
	}
}
