#include <stdio.h>
#include <unistd.h>

int main(int argc , char *argv[])
{
    int i;
    char *str = argv[1];

    i = 0;

    if (argc == 2)
    {
        while (str[i] == ' ') //saltamos los espacios en blanco
            i++;
        while (str[i] != ' ' && str[i] != '\0') // posicion no es blanco y tmpoco nulo ( fin cadena)
            write (1, &str[i++], 1);
    }
    write(1,"\n", 1);
    return 0;
}