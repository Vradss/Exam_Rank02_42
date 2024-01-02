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

int ft_len(int num)
{
	int i = 0;
	if(num <= 0)
		++i;
	while (num != 0)
	{
		++i;
		num = num / 10;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	int			len;
	char		*str;
	long		num;
	int			i;

	num = nbr;
	len = ft_len(nbr);
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';

	//si el numero es negativo
	if (num < 0)
	{
		str[0] = '-';
		num = -num; //se convierte positivo para conversión
		i = 1;
	}
	//si la cadena es 0
	else if (num == 0)
		str[0] = '0';
	//si es + y no 0, se establece en 0 para llenar la cadena desde el primer char
	i = 0;
	while( num != 0)
	{
		--len; //decrementamos para llenar desde el final
		str[len] = num % 10 + '0'; //digito menos significativo
		num = num / 10; // al dividir / 10 se pasa al siguiente digito
	}
	return(str);
	
}
int main()
{
	int i = -2147483648;
	printf("str: %s\n", ft_itoa(i));
	return 0;
}