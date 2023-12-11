#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		size;
	char	*dest;

	i = 0;
	size = 0;
	dest = (char *)malloc(sizeof(*src) * (size + 1));
	if (src[0] == '\0' || dest == NULL)
		return (NULL);
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t			i;
	unsigned char	long_dst;
	size_t			long_src;

	i = 0;
	long_dst = ft_strlen(dst);
	long_src = ft_strlen((char *)src);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	total;
	//size_t	i;
	//size_t	j;

	//i = 0;
	//j = 0;
	if (!s1 || !s2)
		return (0);
	total = ft_strlen((char *)s1) + ft_strlen((char *)s2);;
	s3 = (char *)malloc(total + 1);
	if (!s3)
		return (0);
	ft_strlcat(s3, s1, total + 1);
	ft_strlcat(s3, s2, total + 1);
	/*while (j < i)
	{
		ft_strlcat(s3, s1, total);
		j++;
		if (s2[j + 1])
			ft_strlcat(s3, s1, total);
	}*/
	return (s3);
}
