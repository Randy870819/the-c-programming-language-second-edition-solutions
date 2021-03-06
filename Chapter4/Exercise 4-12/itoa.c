/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 4-12, Chapter4.
 */

#include <stdio.h>
#include <limits.h>
 #include <string.h>

#define MAXLINE 1000

void itoa(int n, char s[]);
void itoa_r(int n, char s[]);

int main(void)
{
    char s[MAXLINE];
    
    itoa(INT_MIN, s);
    printf("%d is converted to %s.\n", INT_MIN, s);
    itoa(826, s);
    printf("%d is converted to %s.\n", 826, s);
    itoa(-2093, s);
    printf("%d is converted to %s.\n", -2093, s);
    itoa(0, s);
    printf("%d is converted to %s.\n", 0, s);
    
    return 0;
}

void itoa(int n, char s[])
{
    s[0] = '\0';
    itoa_r(n, s);
}

void itoa_r(int n, char s[])
{
    int remainder, l;

    if (n / 10)
        itoa_r(n / 10, s);
    else if (n < 0)
        strcat(s, "-");
        
    remainder = n % 10;
    char buf[2] = {((n < 0) ? -remainder : remainder) + '0', '\0'};
    strcat(s, buf); 
}
