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


#include <unistdio.h>
#include <stdlib.h>

int absolute_value(int num)
{
    if(num < 0)
        num *= -1;
    return(num);
}


int     *ft_range(int start, int end)
{
    int i = 0; // indice para llenar el res array
    int len = absolute_value((end - start)) + 1; // longitud de array y +1 para que incluya extremos
    int *res = (int *)malloc(sizeof(int) * len);

    if(res == NULL)
        return NULL;

    if (start <= end)
    {
        while(i < len)
        {
            res[i] = start;
            start++;
            i++;
        }
    }
    else
    {
        while (i < len)
        {
            res[i]= start;
            start--;
            i++;
        }
        
    }
    return(res);
}

#include <stdio.h>

int main() {
    int start = 1;
    int end = -3;

    int *result = ft_range(start, end);

    if (result != NULL) {
        printf("Array resultante: [");
        for (int i = 0; i <= end - start + 1; i++) {
            printf("%d", result[i]);
        }
        printf("]\n");

        free(result);  // Liberar la memoria asignada dinámicamente
    } else {
        printf("Error al asignar memoria.\n");
    }

    return 0;
}
