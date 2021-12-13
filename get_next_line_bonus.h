/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:45:06 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/13 10:17:07 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define MAX_FD 1024

char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_buff_to_memory(int fd, char *memory);
char	*ft_get_line(char *str);
char	*ft_reset_memory(char *memory, char *line);

void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_free(char *buff, char *memory);

size_t	ft_strlen(const char *str);

#endif