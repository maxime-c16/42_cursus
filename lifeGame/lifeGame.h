#ifndef LIFEGAME_H

# define LIFEGAME_H

//# define WINDOW_SIZE 10
# define ALIVE_SYMBOL '0'
# define DEATH_SYMBOL '-'

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <time.h>

typedef struct lifeGame
{
	char	leftCell;
	char	rightCell;
	char	upCell;
	char	dwnCell;
	char	luCell;
	char	ldCell;
	char	ruCell;
	char	rdCell;
	char	state;
}	lives;

char	**ft_split(char *str, char *charset);
int		*get_words_size(char *str, char *charset);
int		is_word(char c, char cbefore, char *charset);
int		get_words_count(char *str, char *charset);
int		is_separator(char c, char *charset);
lives	get_pos(lives pos, unsigned int x, unsigned int y, lives **tab);
lives	pos_x(lives pos, int x, int y, lives **tab);
lives	pos_y(lives pos, int x, int y, lives **tab);
lives	**get_changes(lives **tab);
int		check_survive(lives	cell);
lives	**parse_life(const char *str, lives **tab);
lives	**ft_fill_tab(lives **tab);
lives	**get_struc(lives **tab);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(lives *b, size_t n);
void	ft_print_tab(lives **tab);
int		ft_get_size_parse(const char *str);
int		ft_isdigit(int c);

#endif
