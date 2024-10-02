// Assignment name  : ft_strdup
// Expected files   : ft_strdup.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strdup (man strdup).

// Your function must be declared as follows:

// char    *ft_strdup(char *src);


#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *ft_strdup(char *src)
{
    int i = 0;
    char *dup;

    //contamos la longitud del str
    while (src[i])
        i++;
    //almacenamos memoria para ese str
    dup = (char *)malloc((i + 1) * sizeof(char));

    //reiniciamos el iterador para copiar la cadena
    i = 0;
    while (src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}