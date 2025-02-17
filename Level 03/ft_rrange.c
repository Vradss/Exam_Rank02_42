/*Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0. */

#include <stdlib.h>

int abs(int num)
{
    if(num < 0)
        num *= -1;
    return(num);
}

int     *ft_rrange(int start, int end)
{
    int i = 0;
    int len = (abs(end - start) + 1);
    int *res = (int *)malloc(sizeof(int) * len);

    while (i < len)
    {
        if(start > end)
        {
            res[i] = end;
            end++;
            i++;
        }
        else
        {
            res[i] = end;
            end--;
            i++;
        }
    }
    return(res);

}

//v2


int abs(int n)
{
    if ( n < 0)
        n = n * -1;
    return n;
}

int     *ft_rrange(int start, int end)
{
    int len = abs(end - start) + 1;
    int *res = malloc(sizeof(int) * len);
    int i = 0;

    if ( start <= end)
    {
        while ( i < len)
        {
            res[i] = end;
            end--;
            i++;
        }
    }
    else if (start >= end)
    {
        while ( i < len)
        {
            res[i] = end;
            end++;
            i++;
        }
    }
    return res;
}

int main()
{
    int start = 15;
    int end = 8;
    int len = abs(end - start) + 1;
    int *res = ft_rrange(start, end);
    int i = 0;

    while ( i < len)
    {
        printf("%d--", res[i]);
        i++;
    }
    return 0;

}

