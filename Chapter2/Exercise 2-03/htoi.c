/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 2-03, Chapter2.
 */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
int htoi(char s[]);

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%s: %d\n",line, htoi(line));
    }
    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; (i < lim - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    s[i] = '\0';

    return i;
}

int htoi(char s[])
{
    int n = 0, i = 0;
    char c;

    if ((s[0] == '0') && (s[1] == 'x' || s[1] == 'X'))
        i = 2;

    for (i;  s[i] != '\0'; ++i) {
        c = s[i];
        n *= 16;
        if (c >= '0' && c <= '9')
            n += c - '0';
        else if (c >= 'a' && c <= 'f')
            n += (c - 'a' + 10);
        else if (c >= 'A' && c <= 'F')
            n += (c - 'A' + 10);
        else {
            printf("Some undefined character were detected in the given string!\n");
            n = -1;
            break;        
        }
    }

    return n;
}
