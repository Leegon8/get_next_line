#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

size_t  ft_strlcat(char *dst, const char *src, size_t n)
{
        size_t                  i;
        unsigned char   long_dst;
        size_t                  long_src;

        i = 0;
        long_dst = strlen(dst);
        long_src = strlen((char *)src);
        if (n == 0)
                return (long_src);
        while (src[i] && long_dst < n - 1)
        {
                dst[long_dst] = src[i];
                i++;
                long_dst++;
        }
        dst[long_dst] = '\0';
        return (long_dst + long_src);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *s3;
        size_t  total;

        if (!s1 || !s2)
                return (0);
        total = strlen((char *)s1) + strlen((char *)s2);;
        s3 = (char *)malloc(total + 1);
        if (!s3)
                return (0);
        ft_strlcat(s3, s1, total + 1);
        ft_strlcat(s3, s2, total + 1);

        return (s3);
}

char    *read_bytes(int fd, char *str)
{
        int     rid;
        char    *buffer;

        buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
        if (!buffer)
                return (ft_free(&str));
        buffer[0] = '\0';
        rid = 1;
        while(rid > 0 && !strchr(buffer, '\n'))
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

// Declaración de la función readbuf
int main(int argc, char **argv) 
{
	int	fd;
	char	*str = NULL;

	if (argc != 2)
	{
		printf("Pas de fichier a lire.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1) 
	{
		perror("Error al abrir el archivo");
		return 1;
	}
	str = read_bytes(fd, str);
	size_t	buffer_size = str ? strlen(str) : 0;
	printf("Tamaño del buffer: %zu bytes\n", buffer_size);
	
	close(fd);
	free(str);

	return (0);
}

