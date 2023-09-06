#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *s)
{
    int i;
    i = 0;
    while ( s[i] != '\0')
        i++;
    return i;
}

int main()
{
    char s[] = "Vrados es una pendeja ";
    printf("%d", ft_strlen(s));
    return 0;
}