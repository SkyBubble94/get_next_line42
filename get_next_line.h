/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:45:06 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/03 11:47:25 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *str);

#endif