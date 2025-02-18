/* Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.*/


void sort_int_tab(int *tab, unsigned int size)
{
    int i = 0;
    int temp;

    while ( i < (size - 1))
    {
        if ( tab[i] > tab[ i + 1 ])
        {
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;
            i = 0;
        }
        else 
            i++;
    }
}

#include <stdio.h>
int main()
{
    int array[] = { 4,2,1,3,5};
    int size = 5;
    int i = 0;

    while ( i < size)
    {
        printf("%d", array[i]);
        i++;
    }

    sort_int_tab(array, size);

    printf("Luego de aplicar\n");

    i = 0;
    while ( i < size)
    {
        printf("%d", array[i]);
        i++;
    }

    return 0;

}
