/*
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);
*/

#include <unistd.h>
#include <stdio.h>

void ft_swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 1;
    int b = 5;
    printf("a = %d , b = %d\n", a , b);
    ft_swap(&a,&b);
    printf("new a = %d, new b = %d", a,b);
    return 0;
    
}