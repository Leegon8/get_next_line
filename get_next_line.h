#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE > 9223372036854775806
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

//----------- GNL -------------
char	*get_before_newline(const char *s);
char	*get_after_newline(const char *s);
char	*get_next_line(int fd);
char	*join_and_free(char *line, char *buffer, int *new_line);
char	*new_line(char *buffer);
//---------- UTILS -----------
char	*ft_strdup(const char *src);
int		ft_strlen(char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_malloc_zero(size_t count, size_t size);
void    *ft_memset(void *s, int c, size_t n);
#endif
