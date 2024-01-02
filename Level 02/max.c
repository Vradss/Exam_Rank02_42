/*Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.******* */

#include <unistd.h>
#include <stdio.h>

int		max(int* tab, unsigned int len)
{
    if (len == 0)
        return 0;
    
    unsigned int result; //almacena valor máximo en tab
    unsigned int i = 0;

    result = tab[i]; //se inicia con el primer elemento de tab

    while (i < len)
    {
        if ( result < tab[i])
            result = tab[i];
        i++;
    }
    return (result);
}

int main()
{
    int tab[] = {1 , 5 , 12};
    int len = 3;
    printf("result: %d", max(tab,len));
    return 0;
}

