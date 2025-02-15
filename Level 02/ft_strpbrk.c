/*
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);
*/


// Su propósito principal es buscar en una cadena (string) la primera ocurrencia de 
// cualquiera de un conjunto de caracteres especificado.
// @Parámetros
// s1: Es un puntero a la cadena de entrada en la que se desea buscar.
// s2: Es un puntero a la cadena que contiene los caracteres a buscar.
// @Retorno
// Devuelve un puntero a la primera ocurrencia de cualquiera de los caracteres de s2 en s1.
// Si no se encuentra ningún carácter de s2 en s1, la función devuelve NULL.

#include <string.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
    while (*s1)
    {
        const char *temp = s2; //creamos un puntero temporal para recorrrer s2
        while (*temp)
        {
            if ( *s1 == *temp) 
                return (char *)s1; //retornamos puntero desde la posición donde hay coincidencia
            temp++;
        }
        s1++;
    }
    return(NULL);
}



int main()
{
	char *s1 = "vradis";
	char *s2 = "eoa";
	printf("mia : %s\n", ft_strpbrk(s1,s2));
	printf("original : %s", strpbrk(s1,s2));
	return 0;
}

//ubica la letra en s1 y devuelve string desde ese punto
output : adis



//V2

	
char *ft_strpbrk(const char *s, const char *charset)
{
    int i = 0;
    while (s[i])
    {
        int j = 0;
        while(charset[j])
        {
            if ( s[i] == charset[j])
                return(char *)&s[i];
            j++;
        }
        i++;
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    printf("%s\n", ft_strpbrk(argv[1], argv[2]));
    printf("%s\n", strpbrk(argv[1], argv[2]));
    return 0 ;
}

