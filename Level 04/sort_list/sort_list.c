/*Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function 
pointer cmp to select the order to apply, and returns a pointer to the 
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h 
that is provided to you. You must include that file 
(#include "list.h"), but you must not turn it in. We will use our own 
to compile your assignment.

Functions passed as cmp will always return a value different from 
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list 
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}
*/

#include "list.h"
#include <unistdio.h>
#include <stdlib.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *ptr;
    int swap;

    ptr = lst;
    while(lst->next != NULL)
    {
        if (((*cmp)(lst->data, lst->next->data)) == 0)
        {
            swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;
            lst = ptr;
        }
        else
            lst = lst->next;
    }
    lst = ptr;
    return (lst);
}

//Main 

// int ascending(int a, int b)
// {
// 	return (a <= b);
// }

// void print_list(t_list *lst)
// {
//     while(lst)
//     {
//         printf("%d", lst->data);
//         lst = lst->next;
//     }
//     printf("\n");
// }

// t_list *create_node(int data) {
//     t_list *node = malloc(sizeof(t_list));
//     if (node) {
//         node->data = data;
//         node->next = NULL;
//     }
//     return node;
// }


// int main() {
//     // Crear una lista desordenada
//     t_list *head = create_node(4);
//     head->next = create_node(2);
//     head->next->next = create_node(7);
//     head->next->next->next = create_node(1);
//     head->next->next->next->next = create_node(9);
//     head->next->next->next->next->next = create_node(5);
//     head->next->next->next->next->next->next = create_node(3);

//     printf("Lista original: ");
//     print_list(head);

//     // Llamar a sort_list
//     head = sort_list(head, ascending);  // Asegúrate de tener una función de comparación válida (cmp_function)

//     printf("Lista ordenada: ");
//     print_list(head);

//     // Liberar memoria
//     while (head) {
//         t_list *temp = head;
//         head = head->next;
//         free(temp);
//     }

//     return 0;
// }
