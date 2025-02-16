/*Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>*/

#include <unistd.h>

int main(int argc , char *argv[])
{
	if(argc == 3)
	{
		int ascii[255] = {0};
		int i = 1;
		while(i < 3)
		{
			int j = 0;
			while(argv[i][j])
			{
				if ( ascii[argv[i][j]] == 0)
				{
					ascii[argv[i][j]] = 1;
					write(1, &argv[i][j], 1);
				}
				j++;
			}
			i++;
		}

	}
	write(1, "\n", 1);
	return (0);
}


//v2


#include <unistd.h>

int main(int argc, char *argv[])
{
    char *s1 = argv[1];
    char *s2 = argv[2];
    int i = 0;
    char printed[256] = {0};

    if ( argc == 3)
    {
        while(s1[i])
        {
            if (printed[s1[i]] == 0)
            {
                write(1, &s1[i], 1);
                printed[s1[i]] = 1;
            }
            i++;
        }
        i = 0;
        while(s2[i])
        {
            if (printed[s2[i]]== 0)
            {
                write(1, &s2[i], 1);
                printed[s2[i]] = 1;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
