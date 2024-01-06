#include "ft_gnl.h"
#include <stdio.h>

char	*ft_gnl(int fd)
{
	char	*buffer;
	char	*line;
	int	new_line;
	size_t	bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return(printf("El buffer es nulo\n"));
	line = NULL;
	new_line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

