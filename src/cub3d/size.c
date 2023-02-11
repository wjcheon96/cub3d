#include "cub.h"

int	get_sizec(char	*str, int c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

int	get_size(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_maxlen(char **str)
{
	int	i;
	int	ret;
	int	len;

	i = 0;
	ret = 0;
	while (str[i])
	{
		len = ft_strlen(str[i]);
		if (len > ret)
			ret = len;
		i++;
	}
	return (ret);
}