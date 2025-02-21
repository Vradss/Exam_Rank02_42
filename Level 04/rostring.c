/*Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$> */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char *s1 = argv[1];
    int i = 0;
    int start;
    int end;
    int spaceFinal;

    if ( argc > 1)
    {
        while ( s1[i] == ' ' || s1[i] == '\t')
            i++;
        start = i; // aquí guardamos el primer char de la primera palabra
        while ( s1[i] && s1[i] != ' ' && s1[i] != '\t')
            i++;
        end = i - 1; // aquí guardamos el ultim char de la primera palabra

        //imprimimos el resto de palabras
        while ( s1[i] == ' ' || s1[i] == '\t')
            i++;
        while (s1[i])
        {
            spaceFinal = 1;
            while ( s1[i] == ' ' && s1[i + 1] == ' ') //elimina espacios consecutivos.
                i++;
            write(1, &s1[i], 1);
            i++;
        }
        //añadimos ese espacio final
        if (spaceFinal == 1)
            write(1, " ", 1);

        //print primera palabra
        while ( start <= end)
        {
            write(1, &s1[start], 1);
            start ++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
