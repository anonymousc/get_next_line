#include <stdio.h>

char *swap(char *s , char *b)
{
    int i,j = 0;

    static char *tmp;
    while (s[i] && b[j])
    {
        tmp = s[i];
        s[i] = b[j];
        b[j+i] = tmp;
        i++;
        j++;
    }
    
}