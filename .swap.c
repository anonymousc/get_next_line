#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strjoin(char *s, char *s1)
{
    char *p;
    int  i = 0;
    int j = 0;
    int total = strlen(s) + strlen(s1) + 1;
    p = (char *)malloc(total);
    while (s[i])
    {
        p[i] = s[i]; 
        i++;
    }
    while (s1[j])
    {
        p[i + j] = s1[j];
        j++;
    }
    p[i + j] = '\0';
    return(p);
}
int main()
{
    char *d = " test";
    char *s = "admin";
    char *s1 = strjoin(s,d);
    printf("%s",s1);
    system("leaks a.out");
   
}