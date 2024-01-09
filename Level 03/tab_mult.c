/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/

#include <unistd.h>

int ft_atoi(char *str)
{
    int n = 0;
    while(*str != '\0')
    {
        n = n * 10 + *str - '0';
        str++;
    }
    return(n);
}

void ft_putnbr(int num)
{
    if (num >= 10)
        ft_putnbr( num / 10);
    char c = ( num % 10) + '0';
    write(1, &c, 1);
}

int main(int argc, char *argv[])
{
    int i = 1;
    int num = ft_atoi(argv[1]);

    if (argc == 2)
    {
        while (i <= 9)
        {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(num);
            write(1, " = ", 3);
            ft_putnbr( i * num);
            write(1, "\n", 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);

}