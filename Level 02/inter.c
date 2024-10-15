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

int main(int argc, char *argv[])
{
    char *s1 = argv[1];
    // Array para marcar caracteres ya impresos inicializamos en 0
    char printed[256] = {0}; 
    char *s2 = argv[2];
    int i = 0;
    int j ;

    if (argc == 3)
    {
        while (s1[i])
        {
            j = 0;
            while (s2[j])
            {
                if (s1[i] == s2[j] && printed[s1[i]] == 0) //Si carácter es igual en ambas cadenas y no ha sido impreso anteriormente 
                {
                    write(1, &s1[i], 1);
                    printed[s1[i]] = 1; // Marcamos el carácter como impreso
                    break;
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}

