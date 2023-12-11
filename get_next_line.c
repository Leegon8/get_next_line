#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

/* FUNCIÓN PRINCIPAL:
 * 
 * Char *buffer -->  representa el bloque de lectura;
 * Char *line --> Puntero que almacena los bloques leídos siempre y cuando no haya un '\n' o final de línea.
 * Int new_line --> Verifica si el bloque de lectura contiene '\n'.
 * Size_t bytes_read --> Num de bytes que se ha leído en el buffer y que hay que reservar.
 */

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	int		new_line;
	size_t	bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	line = NULL;
	new_line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		line = join_and_free(line, buffer, &new_line);
		if (new_line)
			break ;
	}
	free(buffer);
	return (line);
}

// Función que verifica si dentro del buffer hay un salto de línea
char	*find_newline(char *buffer)
{
	while (*buffer)
	{
		if (*buffer == '\n')
			return (buffer);
		buffer++;
	}
	return (NULL);
}

//Función que concatena buffer con line usando un char* temporal 
//para almacenar el contenido de line
char	*join_and_free(char *buffer, char *line, int *new_line)
{
	char	*joined;
	char	*tmp;
	char	*nl_position;

	nl_position = find_newline(buffer);
	if (nl_position != NULL)
	{
		*new_line = 1;
		*nl_position = '\0';
	}
	if (line == NULL)
		tmp = "";
	else
		tmp = line;
	joined = ft_strdup(tmp);
	joined = ft_strjoin(joined, buffer);
	free(line);
	return (joined);
}

/*
int main()
{
	int fd;

	// Para abrir el fichero:
	fd = open("archive.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo\n");
	}
	else 
		read_fd(
	return 0;
}*/
