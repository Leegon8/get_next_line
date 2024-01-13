#include "get_next_line.h"

// Función que libera los punteros
char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

//Función que limpia/libera el buffer (llamado str en esta función)
//que lee el contenido de las líneas
char	*ft_clean(char *str)
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
	return (line);
}

// Función que lee datos de un archivo descriptor y 
// acumularlos en un almacenamiento dinámico (buffer)
char	*read_bytes(int fd, char *str)
{
	int	rid;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free(&str));
	buffer[0] = '\0';
	rid = 1;
	while (rid > 0 && !ft_strchr(buffer, '\n'))
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

/* FUNCIÓN PRINCIPAL:
 * 
 * Char *buffer --> Representa el bloque de lectura;
 * Char *line --> Puntero que almacena los bloques leídos siempre y 
 * 		  cuando no haya un '\n' o final de línea.
 *
 * Int new_line --> Verifica si el bloque de lectura contiene '\n'.
 * Size_t bytes_read --> Num de bytes que se ha leído en el buffer 
 * 			 y que hay que reservar.
 */
char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str || !ft_strchr(str, '\n'))
		str = read_bytes(fd, str);
	if (!str)
		return (NULL);
	line = find_newline(str);
	if (!line)
		return (ft_free(&str));
	str = ft_clean(str);
	return (line);
}
