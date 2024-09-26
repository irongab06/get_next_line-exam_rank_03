#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int	ft_check_buffer(char *buffer, int stop)
{
	while (buffer[stop])
	{
		if (buffer[stop] == '\n')
			return (1);
		stop++;
	}
	return (0);
}

char	*get_line(char *buffer, int *stop)
{
	char	*line;
	int	i;

	i = 0;
	line = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	if (line == NULL)
		return (NULL);
	while (buffer[*stop])
	{
		line[i] = buffer[*stop];
		i++;
		(*stop)++;
		if (buffer[*stop - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[2000000];
	static int	stop = 0;
	char	*temp;
	int	j;
	int	i;
	int	beat_read;

	i = ft_strlen(buffer);
	j = 0;
	beat_read = 0;
	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp == NULL)
		return (NULL);
	if (ft_check_buffer(buffer, stop))
	{
		free(temp);
		return (get_line(buffer, &stop));
	}
	while ((beat_read = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		temp[beat_read] = '\0';
		j = 0;
		while (j < beat_read)
		{
			buffer[i++] = temp[j++];
		}
		buffer[i] = '\0';	
		if (ft_check_buffer(buffer, stop))
		{
			free(temp);
			return (get_line(buffer, &stop));
		}
	}
	if ((ft_strlen(buffer + stop)) > 0)
	{
		free(temp);
		return (get_line(buffer, &stop));
	}
	free(temp);
	return (NULL);
}
