#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char status[2] = "OK";
    char buff[32];

    setbuf(stdout, NULL);

    puts("Give me your name, and I'll check if your status is OK");
    gets(buff);
    if (strncmp(status, "OK", 2) == 0)
        system("cat flag.txt");
    else
        puts("Try again. Bye.");
}
