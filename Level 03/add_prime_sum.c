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

#include <unistd.h>
//Convert string to int
int ft_atoi(char *str)
{
    int num = 0;

    while(*str >= '0' && *str <= '9')
    {
        num = num * 10;
        num += *str - '0';
        ++str;
    }
    return (num);
}

//Recursión para imprimir digito por digito
void    ft_putnbr(int n)
{
    if (n >= 10)
        ft_putnbr( n / 10);
    char digit = (n % 10) + '0';
    write(1, &digit ,1);
}

int ft_prime(int num)
{
    int i = 2;
    if(num <= 1) //numeros menores a 1 , no son primos
        return(0);
    //si num no es primo, debe tener 1 dividor que es <= a su raiz cuadrada
    while(i * i <= num)
    {
        if (num % i == 0)
            return(0);
        i++;
    }
    return (1);
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int nbr = ft_atoi(argv[1]);
        int sum = 0;

        while (nbr > 0)
        {
            if (ft_prime(nbr))
                sum = sum + nbr;
            nbr--;
        }
        ft_putnbr(sum);
    }
    write(1,"\n",1);
    return (0);
}