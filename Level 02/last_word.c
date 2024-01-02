/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/
#include <unistd.h>

int main( int argc , char *argv[])
{
    char *str = argv[1];
    int i = 0;

    if ( argc == 2)
    {
        while(str[i] != '\0')
            i++;
        i--; //retrocedemos para acceder al ultimo caracter de la cadena
        while((str[i] == '\t' || str[i] == ' ') && i >= 0) //eliminar espacios y tabs
            i--;
        while (str[i] != '\t' && str[i] != ' ' && i >= 0) //moverlo hacia inicio de la ultima palabra
            i--;
        i++; //avanzar apunta primer char de last word
        while(str[i] && str[i] != '\t' && str[i] != ' ') //imprimimos last word
        {
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}