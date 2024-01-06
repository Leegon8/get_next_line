#include "get_next_line.h"
#include <stdio.h>

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
	if (buffer == NULL)
		return (NULL);
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	line = NULL;
	new_line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		perror("Error en los parametros de entrada");
		free(buffer);
		return (NULL);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == (size_t) - 1)
	{
		perror("Error al leer el archivo");
		free(buffer);
		exit(EXIT_FAILURE);
	}
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		line = join_and_free(line, buffer, &new_line);
		if (new_line)
			break;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (line);
}

// Busca el '\n' y crea un substr. 
char	*find_newline(char *str)
{
	char	*nl_position;
	char	*line;
	size_t	len;

	nl_position = ft_strchr(str, '\n');
	len = (nl_position - str) + 1;
	line = ft_substr(str, 0, len);
	if (!line)
		return (NULL);
	return (nl_position);
}

// Función que lee datos de un archivo descriptor y acumularlos en un almacenamiento
// dinámico (buffer)
char	*read_bytes(int fd, char *str)
{
	int	rid;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free(&str));
	buffer[0] = '\0';
	rid = 1;
	while(rid > 0 && !ft_strchr(buffer, '\n'))
	{
		rid = read(fd, buffer, BUFFER_SIZE);
		if (rid > 0)
		{
			buffer[rid] = '\0';
			str = ft_strjoin(str, buffer);
		}
	}
	if (rid == -1)
		return (ft_free(&str));
	return (str);
}

//Función que limpia/libera el buffer
char	*ft_clean(char *buffer)
{
	char	*ptr;
	char	*line;
	size_t	len;

	ptr = ft_strchr(str, '\n');
	if (!ptr)
		return (ft_free(&str));
	len = (ptr - str) + 1;
	if (!str[len])
		return (ft_free(&str));
	line = ft_substr(str, len, ft_strlen(str) - len);
	ft_free(&str);
	return (line);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
