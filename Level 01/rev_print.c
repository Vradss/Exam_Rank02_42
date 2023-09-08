/*
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
*/
#include <unistd.h>

int main(int argc , char *argv[])
{
    char *str = argv[1];
    int i = 0;

    if ( argc == 2)
    {
        while (str[i] != '\0')
            i++;
        while ( i >= 1)
        {
            write(1, &str[i - 1], 1);
            i--;
        }
    }
    write(1, "\n", 1);
    return 0;
}