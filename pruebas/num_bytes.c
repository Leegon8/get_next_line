//crear funcion que calcule la mamoria de la primera linea
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


//=========== PART TWO ==============

char	*get_line(const char *s)
{
	char	*result;
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	result = (char *)malloc(sizeof * s);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	main(void)
{
	char	str[] = "tu eres el único";

	printf("%s\n", get_line(str));
	return (0);
}


/*
=========== PART ONE ============


size_t  calculate_buff(char *str)
{
	int	i;
	
	i = 0;
	if (!*str)
		return(0);
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	*reserva_memoria(char *str)
{
	char	*result;

	result = 0;
	if (calculate_buff(str) == 0)
		return ("NULL");
	if (calculate_buff(str) > 0)
	{
		result = ft_strdup(str);
	}
	return (result);
}

char    *ft_strdup(const char *src)
{
        int             i;
        int             size;
        char    *dest;

        i = 0;
        size = 0;
        dest = (char *)malloc(sizeof(*src) * (size + 1));
        if (src[0] == '\0')
                return (NULL);
        if (dest != malloc(sizeof(char) * (size + 1)))
                return (NULL);
        i = 0;
        while (src[size])
                size++;
        while (src[i])
        {
                dest[i] = src[i];
                i++;
        }
        dest[i] = '\0';
        return (dest);
}
//PROTOTYPE FUNCTION READ:
//
//ssize_t read_line(int fd, char *buf, size_t count);
//
//============ MAIN CON int fd =============
/
int main(void)
{
	
	int	fd;
	
	//para abrir el archivo o crearlo
	fd = open("test.txt", O_WRONLY | O_CREAT);
	if (fd == -1)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	else
	{
		size_t	count;
		char	buffer[];

		buffer =
		count = calculate_buff(str);
		printf("Archivo creado / abierto adecuadamente :)\n");
		read(fd, (void *)0, count);
	}
	//printf("%ld", calculate_buff(str));
	return (0);
}*/
