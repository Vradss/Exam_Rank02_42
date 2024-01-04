/*Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$> */

/// @brief 
/// @param begin_list a pointer to a pointer to the first element of linked list
/// @param data_ref data to compare
/// @param cmp a function that compares 2 elementos and return 0 if they are equal

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    if (begin_list == NULL || *begin_list == NULL)
        return;
    
    t_list  *ptr;
    ptr = *begin_list;

    if (cmp(ptr->data, data_ref) == 0)
    {
        *begin_list = ptr->next;
        free(ptr);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    ptr = *begin_list;
    ft_list_remove_if(&ptr->next, data_ref, cmp);
}
