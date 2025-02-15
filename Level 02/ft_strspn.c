/*
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);

La función strspn cuenta el número de caracteres en el inicio de la cadena s que coinciden 
con los caracteres de la cadena accept. En otras palabras, comienza desde el principio de s 
y cuenta cuántos caracteres son también parte de accept hasta que encuentra un carácter que no está en accept. 
En ese momento, deja de contar y devuelve el total de caracteres que coincidieron.

*/
#include <stddef.h>
#include <string.h>
#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
    int i = 0; //itera sobre accept
    int num_coin = 0; //almacena el numero de coincidencias
    
    while(s[num_coin])
    {
        while( accept[i] && accept[i] != s[num_coin])
            i++;
        if(!accept[i]) //si no se encontro ninguna coincidencia
            break; //salimos del bucle
        num_coin++;
    }
    return num_coin;
}

int main()
{
	char *s1 = "bri";
	char *s2 = "sabrina";

	printf("mia: s1 = %s, s2 = %s, result = %lu\n", s1 , s2 , ft_strspn(s1,s2));
	printf("original : s1 = %s, s2 = %s, result = %lu\n", s1, s2 , strspn(s1,s2));
	printf("original : s1 = %s, s2 = %s, result = %lu\n", s1, s2 , strcspn(s1,s2));
	return 0;
}

output : 3 

// new

#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
    size_t i = 0;
    size_t j ;

    while(s[i])
    {
        j = 0;
        while(accept[j])
        {
            if ( s[i] == accept[j])
                break;
            j++;
        }
        if (!accept[j])
            return i;
        i++;
    }
    return i;
}

#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    (void)argc;
    char *s1 = argv[1];
    char *accept = argv[2];
    
    printf("%zu\n", ft_strspn(s1, accept));
    printf("%lu\n", strspn(s1, accept));
}
