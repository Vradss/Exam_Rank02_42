/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);

Busca la primera coincidencia entre la cadena s y la cadena reject. Si encuentra una coincidencia, devuelve la posición de la coincidencia en s; de lo contrario, devuelve la longitud de s (es decir, el final de s) como indicación de que no se encontraron coincidencias.
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t len;
	int i;

	len = 0;

	while(s[len]) //verificamos que exista la long de string y llegue final string
	{
		i = 0; //bucle de inicializa en 0 para comenzar la busqueda en reject desde inicio
		while(reject[i] != '\0') //bucle para buscar los caraceres en reject
		{
			if(s[len] == reject[i])
				return(len); //si se encuentra la coincidencia devuelve la posicion len que es la distancia desde el principio de la candea s hasta el primer caracteer que coincide reject//
			i++; //sigue recorriendo la cadena para encontra coincidencia en reject
		}
		len++;//sigue recorriendo para avanzar en string s
	}
	return(len); //si no hay coincidencia se devuelve len de string 
}

int main()
{
	char *s1 = "vradis";
	char *s2 = "florez";

	printf("mia: s1 = %s, s2 = %s, result = %lu\n", s1 , s2 , ft_strcspn(s1,s2));
	printf("original : s1 = %s, s2 = %s, result = %lu", s1, s2 , strcspn(s1,s2));
	return 0;
}


//v2


size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;
    size_t j ;

    while(s[i])
    {
        j = 0;
        while(reject[j])
        {
            if ( s[i] == reject[j])
                return (i);
            j++;
        }
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
    
    printf("%lu\n", ft_strcspn(s1, accept));
    printf("%lu\n", strcspn(s1, accept));

    return 0 ;
}
