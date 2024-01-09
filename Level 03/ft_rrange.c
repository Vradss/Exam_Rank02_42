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

int absolute_value(int num)
{
    int i = 0;
    while(num < i)
        return(-num);
    return(num);
}


int     *ft_rrange(int start, int end)
{
    int i = 0;
    int len = (absolute_value(end - start) + 1);
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

#include <stdio.h>

int main() {
    int start = 0;
    int end = -3;

    int *result = ft_rrange(start, end);

    if (result != NULL) {
        printf("Array resultante: [");
        for (int i = 0; i <= end - start; i++) {
            printf("%d", result[i]);
            if (i < end - start) {
                printf(", ");
            }
        }
        printf("]\n");

        free(result);  // Liberar la memoria asignada dinámicamente
    } else {
        printf("Error al asignar memoria.\n");
    }

    return 0;
}
