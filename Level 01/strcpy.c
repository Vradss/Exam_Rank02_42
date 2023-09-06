#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_strcpy(char *dest, char *src)
{
    int i ;
    i = 0;
    while ( src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int main()
{
    char src[] = "vradis es prueba y chevre";
    char *dest = malloc(sizeof(char) + strlen(src) + 1);
    printf("%s", ft_strcpy(dest, src));
    return 0;
}