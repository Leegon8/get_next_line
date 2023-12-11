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
}
