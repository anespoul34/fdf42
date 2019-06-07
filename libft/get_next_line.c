/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:47:08 by anespoul          #+#    #+#             */
/*   Updated: 2016/02/18 13:00:33 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_buffer			*ft_create_buf(int fd)
{
	t_buffer		*buf;

	buf = malloc(sizeof(t_buffer));
	buf->content = ft_strnew(BUFF_SIZE + 1);
	buf->count = 0;
	buf->fd = fd;
	buf->size = BUFF_SIZE;
	return (buf);
}

void				ft_buf_add(t_buffer *buf, char *data, unsigned int size)
{
	int				i;
	int				c;
	char			*tmp_buffer;
	char			*new_buffer;

	i = 0;
	c = -1;
	while (data[i])
	{
		if (buf->count == buf->size)
		{
			size = BUFF_SIZE + buf->size + 1;
			new_buffer = malloc(sizeof(char) * (size));
			while (++c < (int)buf->count)
				new_buffer[c] = buf->content[c];
			tmp_buffer = buf->content;
			buf->content = new_buffer;
			buf->size = size;
			free(tmp_buffer);
		}
		buf->content[buf->count] = data[i];
		i++;
		buf->count = buf->count + 1;
	}
	buf->content[buf->count] = '\0';
}

int					ft_check(t_buffer **buf, char **line, int size, char *tmp)
{
	int i;

	i = 0;
	if ((*buf)->content[size] == '\n')
		return (size + 1);
	while ((*buf)->content[size])
	{
		if ((*buf)->content[size] == '\n')
		{
			tmp[i] = '\0';
			*line = tmp;
			size++;
			if ((*buf)->content[size] == '\0')
				return (ft_strlen((*buf)->content));
			return (size);
		}
		tmp[i] = (*buf)->content[size];
		size++;
		i++;
	}
	tmp[i] = '\0';
	*line = tmp;
	return (ft_strlen((*buf)->content));
}

int					ft_line(t_buffer **buf, char **line)
{
	char			*tmp;
	int				i;
	static int		size = 0;

	tmp = *line;
	i = 0;
	if (!(tmp = malloc(sizeof(char) * ((*buf)->size))))
		return (-1);
	if (size >= (int)ft_strlen((*buf)->content))
	{
		buf = NULL;
		size = 0;
		free(tmp);
		return (0);
	}
	else
	{
		size = ft_check(buf, line, size, tmp);
		return (1);
	}
}

int					get_next_line(int const fd, char **line)
{
	static t_buffer	*buf;
	char			*data;
	int				ret;

	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	if (!buf || buf->fd != fd)
	{
		data = ft_strnew(BUFF_SIZE);
		buf = ft_create_buf(fd);
		while ((ret = read(fd, data, BUFF_SIZE)) > 0)
		{
			ft_buf_add(buf, data, BUFF_SIZE);
			data = ft_strnew(BUFF_SIZE);
		}
		if (ret == -1)
			return (-1);
	}
	return (ft_line(&buf, line));
}
