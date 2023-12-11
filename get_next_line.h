#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD 256
# endif

//----------- GNL -------------
char	*get_next_line(int fd);
char	*join_and_free(char *line, char *buffer, int *new_line);
char	*new_line(char *buffer);
//---------- UTILS -----------
char	*ft_strdup(const char *src);
int		ft_strlen(char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
