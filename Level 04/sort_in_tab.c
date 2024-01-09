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

#include <unistdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = 0;
    int temp;

    while (i < (size - 1))
    {
        if ( tab[i] > tab[i + 1])
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

// int main() {
//     int arr[] = {4, 2, 7, 1, 9, 5, 3};
//     unsigned int size = sizeof(arr) / sizeof(arr[0]);

//     printf("Original array: ");
//     for (unsigned int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     sort_int_tab(arr, size);

//     printf("Sorted array: ");
//     for (unsigned int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     return 0;
// }