/*Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3. */


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int abs(int num)
{
    if(num < 0)
        num *= -1;
    return(num);
}

int     *ft_range(int start, int end)
{
    int i = 0;
    int len = abs(end - start) + 1;
    int *res = malloc(sizeof(int) * len);

    if (start <= end)
    {
        while( i < len)
        {
            res[i] = start;
            start++;
            i++;
        }
    }
    else
    {
        while(i < len)
        {
            res[i] = start;
            start--;
            i++;
        }
    }
    return (res);
}

// int main()
// {
//     int start = -5;
//     int end = 4;
//     int len = abs(end - start) + 1;
//     int i = 0;
//     int *res = ft_range(start, end);

//     while ( i < len)
//     {
//         printf("%d-->", res[i]);
//         i++;
//     }
//     return 0 ; 
// }
