#include "../get_next_line.h"
#include <fcntl.h>
#include <limits.h>
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	if (argc != 2)
	{
		printf("Pas de fichier a lire.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Fichier impossible a lire.\n");
		return (0);
	}
	int	line_count = 1;
	while ((line = ft_gnl(fd)) != NULL)
	{
		printf("Ligne %d : %s\n", line_count, line);
		free(line);
		line_count++;
	}
	close(fd);
	return (0);
}
