/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 2-02, Chapter2.
 */

#include <stdio.h>

#define MAXLINE 1000

int main(void)
{
    char line[MAXLINE];
    int c, i;

    for(i = 0; (i < MAXLINE - 1) & ((c=getchar()) != '\n') & (c != EOF); ++i) { 
        line[i] = c;
    }
    line[i] = '\0';

    printf("%s\n", line);

    return 0;
}
