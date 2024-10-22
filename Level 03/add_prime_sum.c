/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/


//Un número primo es primo cuando es divisible entre si mismo y 1

#include <unistd.h>

int atoi (char *str)
{
    int i = 0;
    int res = 0;
    while (str[i])
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res);
}

void putnbr(int n)
{
    if ( n >= 10)
        putnbr(n / 10);
    char c = (n % 10) + '0';
    write(1, &c, 1);
}

//Verificamos si es primo
int is_prime(int n)
{
    int i = 2;
    if ( n < 2) //todo numero < a 2 no es primo.
        return 0;
    while ( i * i <= n)
    {
        if ( n % i == 0)// si tiene un divisor distinto de si mismo y 1, no es primo
            return 0; //si n es divisible por i, no es primo
        i++;
    }
    return 1; // si no se encuentra ningun divisor es primo
}


int main(int argc, char *argv[])
{

    if ( argc == 2)
    {
        int num = atoi(argv[1]);
        int sum = 0;
        
        while ( num > 0) //necesitamos los inferiores 
        {
            if (is_prime(num)) //Si num es primo, lo suma;
                sum = sum + num;
            num--; //retrocedemos al inferior de num
        }
        putnbr(sum); //imprimimos la suma de los primos
    }
    write(1, "\n", 1);
    return 0;
}