/* Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

void lowercase(char *str)
{
    int  i = 0;
    while(str[i])
    {
        if ( str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
}

int ft_strchr(char *str, char c)
{
    int i = 0;
    while(str[i])
    {
        if ( str[i] == c)
            return i ;
        i++;
    }
    return -1;
}

int	ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int j = 0;
    int res = 0;
    int sign = 1;
    char base[16] = "0123456789abcdef";

    //verificamos que la base es válida
    if ( str_base >= 2 && str_base <= 16)
    {
        lowercase((char *) str);
        while ( str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
            i++;
        if ( str[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if ( str[i] == '+')
            i++;
        
        //Al procesar j >= 0, aseguramos que el caracter esta en la cadena base.
        //Si fuera menor <, procesaría caracteres inválidos
        while(str[i] && (j = ft_strchr(base, str[i])) >= 0)
        {
            res = res * str_base;
            res = res + j;
            i++;
        }
    }
    return( res * sign);
}


// #include <stdio.h>

// int main()
// {
//     char str[] = "7B";
//     int base = 16;

//     printf("%d\n", ft_atoi_base(str, base));
//     return 0;
// }

//Output: 123