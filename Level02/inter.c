/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char *s1 = argv[1];
    char *s2 = argv[2];

    if (argc == 3)
    {
        while(*s1 != '\0')
        {
            char *temp = s2; //creamos un puntero para inicializar en s2
            while(*temp != '\0')
            {
                if ( *s1 == *temp) //si el caracter s1 es igual a temp, lo imprime
                {
                    write(1, s1,1);
                    break; // sale del bucle cuando encuentra coincidencia 
                }
                temp++; // avanzamos puntero al siguiente char en s2
            }
            s1++; // avanza puntero al siguiente char en s1
        }
    }
    write(1, "\n", 1);
    return 0;
}

