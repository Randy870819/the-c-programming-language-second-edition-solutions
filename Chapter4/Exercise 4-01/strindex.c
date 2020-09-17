/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 4-01, Chapter4.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int getchars(char s[], int max);
int strindex(char source[], char searchfor[]);
int KMPsearch(char source[], char pattern[]);
void Compute_prefix(char pattern[], int arr[]);

int main(void)
{
    char source[MAXLINE];
    char pattern[MAXLINE];

    printf("Input source, then press enter:\n");
    while (getchars(source, MAXLINE) == 0)
        ;

    printf("Input pattern, then press enter:\n");
    while (getchars(pattern, MAXLINE) == 0)
        ;

    printf("The position is: %d\n", strindex(source, pattern));

    return 0;
}

int getchars(char s[], int max)
{
    int c, i, l;

    for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < max - 1)
            s[l++] = c;
    s[l] = '\0';

    return l;
}

int strindex(char s[], char t[])
{
    
    return KMPsearch(s, t);
}

void Compute_prefix(char pattern[], int *arr)
{
    int m = strlen(pattern);
    
    arr[0] = -1;

    int k = -1;

    for(int q=1; q<m; ++q)
    {
        while(k>=0 && pattern[k+1]!=pattern[q])
            k = arr[k];

        if(pattern[k+1]==pattern[q])
            ++k;

        arr[q] = k;

    }
}
    
int KMPsearch(char source[], char pattern[])
{
    int n = strlen(source);
    int m = strlen(pattern);

    int *arr = malloc(m * sizeof(int));
    Compute_prefix(pattern, arr);
    
    int q = -1, pos = -1;
    
    for(int i=0; i<n; ++i)
    {
        while(q>=0 && pattern[q+1]!=source[i])
            q = arr[q];
        if(pattern[q+1]==source[i])
            ++q;

        if(q==m-1)
            pos = i - (m - 1);
    }

    free(arr);
    return pos;
}
