/* 
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);*/


// Se calcula la longitud necesaria para representar el número como una cadena.
// Se asigna memoria dinámicamente para la cadena.
// Se llena la cadena con los dígitos del número, comenzando desde el final.
// Se manejan casos especiales para números negativos y cero.
// Se devuelve la cadena resultante.

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// n <= 0, while ( n!= 0)

#include <limits.h>
int len_num(int n)
{
    int i = 0;
    if ( n <= 0)
        i++;
    while(n != 0)
    {
        i++;
        n = n / 10;
    }
    return i;
}

int ft_abs (int n)
{
    if ( n <= 0)
        return n = n * -1;
    return n;
}

#include <stdlib.h>

// num < 0, num == 0, num != 0

char	*ft_itoa(int nbr)
{
    int len = len_num(nbr);
    char *res = (char *)malloc(sizeof(char *) * len + 1);
    int num = nbr;

    res[len] = '\0';

    if ( num < 0)
        res[0] = '-';
    else if ( num == 0)
        res[0] = '0';

    while(num != 0)
    {
        len--;
        res[len] = ft_abs(num % 10) + '0';
        num = num / 10;
    }
    return res;
}


int main()
{
	int i = -2147483648;
	printf("str: %s\n", ft_itoa(i));
	return 0;
}
