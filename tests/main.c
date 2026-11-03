#include <fcntl.h>
#include <limits.h>
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

//	printf("---------------------------\nBUFFER_SIZE\t=\t%llu\n---------------------------\n", (unsigned long long int)BUFFER_SIZE);
//	printf("---------------------------\nINT_MAX\t\t=\t%d\nLONG_MAX\t=\t%ld\nLL_MAX\t\t=\t%lld\nULL_MAX\t\t=\t%llu\n---------------------------\n", INT_MAX, LONG_MAX, LLONG_MAX, ULLONG_MAX);
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
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	close(fd);
	return (0);
}

/*
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("archive.txt", O_RDONLY); // Reemplaza "test.txt" con tu archivo de prueba
    if (fd == -1)
    {
        printf("Error al abrir el archivo");
        return 1;
    }

    char *line;
    int line_count = 1;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s\n", line_count, line);
        free(line);
        line_count++;
    }
    close(fd);
    return 0;
}*/
