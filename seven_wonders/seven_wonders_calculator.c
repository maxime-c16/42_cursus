#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;

	i = 0;
	cpy = malloc(sizeof(char) * (len + 1));
	if (!s || !cpy)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (cpy);
	while (i < len)
	{
		cpy[i] = s[start + i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static int	word_count(char const *s, char c)
{
	int		wd;
	int		i;

	i = 0;
	wd = 0;
	if (s[0] != c)
		wd++;
	while (s[++i])
	{
		if (s[i] != c && s[i - 1] == c)
			wd++;
	}
	return (wd);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		ind;
	char	*tmp;
	char	**tab;

	i = -1;
	ind = -1;
	tab = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!s || !tab)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			j = 0;
			while (s[i + j] && s[i + j] != c)
				j++;
			tmp = ft_substr(s, i, j);
			tab[++ind] = tmp;
			i += j - 1;
		}
	}
	return (tab);
}

//make a function that will parse av and store every argument in -Red -coinn -wonders -blue -orange -purple -green except for the first one
int	wonders(char **av)
{
	int		res;
	int		red;
	int		coinn;
	int		wonders;
	int		blue;
	int		orange;
	int		purple;
	int		min;
	int		nul;
	char	**green;
	char	**split;

	res = 0;
	printf("red:\t\t");
	scanf("%d", &red);
	printf("coinn:\t\t");
	scanf("%d", &coinn);
	printf("wonders:\t");
	scanf("%d", &wonders);
	printf("blue:\t\t");
	scanf("%d", &blue);
	printf("orange:\t\t");
	scanf("%d", &orange);
	printf("purple:\t\t");
	scanf("%d", &purple);
	green = ft_split(av[1], ' ');
	if (red > 0)
		res += red;
	if (coinn > 0)
		res += coinn;
	if (wonders > 0)
		res += wonders;
	if (blue > 0)
		res += blue;
	if (orange > 0)
		res += orange;
	if (purple > 0)
		res += purple;
	if (green[0] != NULL)
	{
		min = atoi(green[0]);
		nul = 1;
		for (int i = 0; i < 3; i++)
		{
			if (atoi(green[i]) > 0)
			{
				if (min > atoi(green[i]))
					min = atoi(green[i]);
				res += (atoi(green[i]) * atoi(green[i]));
			}
			if (green[i][0] == '0')
				nul = 0;
		}
		min *= nul;
		if (min > 0)
			res += (min * 7);
	}
	return (res);
}

int	main(int ac, char **av)
{
	printf("total wonders points:\t%d\n", wonders(av));
	return (0);
}
