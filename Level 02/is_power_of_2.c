/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
*/

#include <unistd.h>
#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
    return ((n != 0)&& !(n & ( n - 1)));
}


int main()
{
    printf("result: %d\n", is_power_of_2(10));
    printf("result: %d\n", is_power_of_2(4));
    printf("result: %d\n", is_power_of_2(9249572));
    printf("result: %d\n", is_power_of_2(-4));
    return 0; 
}