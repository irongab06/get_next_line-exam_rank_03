#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int ft_strlen(char *str);
int	ft_check_buffer(char *buffer, int stop);
char *get_line(char *buffer, int *stop);
char *get_next_line(int fd);

#endif