#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int N;
	int	sec;
    scanf("%d", &N);
    int tab[N];
    for (int i = 0; i < N; i++) {
        int pi;
        scanf("%d", &pi);
        tab[i] = pi;
    }
    for (int i = 1; i < N; ++i)
    {
        if (tab[0] < tab[i])
        {
			sec = i;
    		tab[0] = tab[i];
        }
    }
	printf("tab[0] = %d\n", tab[0]);
	printf("tab[] = %d\n", tab[sec]);
    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("%d\n", tab[0] - tab[1]);

    return 0;
}
