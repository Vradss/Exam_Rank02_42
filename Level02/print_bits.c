/* Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010" */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
    int i = 8;
    unsigned char bit;

    while(i--)  //se ejecutara 8 veces
    {
        bit = (octet >> i & 1) + '0';
        //octet desplaza lugares a derecha
        write(1, &bit, 1);
    }
}

int main(void)
{
    print_bits(2);
    return 0;
}
