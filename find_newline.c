#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Busca la '\n' y crea una substr.

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		res = malloc(sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len && start < ft_strlen(s) && s[start])
		res[i] = s[start++];
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (!(char)c)
		return (s);
	return (NULL);
}

char    *find_newline(char *str)
{
        char    *nl_position;
        char    *line;
        size_t  len;

        nl_position = ft_strchr(str, '\n');
        len = (nl_position - str) + 1;
        line = ft_substr(str, 0, len);
        if (!line)
                return (NULL);
        return (line);
}

int main()
{
	char	str[] = "When is time, it won't matter.\n Cause I will always love u";
	char	*result;

	result = find_newline(str);
	printf("%s\n", result);
	printf("%s\n", find_newline(str));
	return (0);
}

