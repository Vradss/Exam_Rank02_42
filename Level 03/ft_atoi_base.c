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

#include <unistdio.h>
#include <stdlib.h>

void    lowercase(char *str)
{
    int i = 0;
    while(str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z' )
            str[i] += 32;
        i++;
    }
}

int ft_strchr(char *str, char c)
{
    int i = 0;
    while(str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
}


int	ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int j = 0;
    int res = 0;
    int sign = 1;
    char base[16] = "0123456789abcdef";

    if(str_base > 1 && str_base <= 16)
    {
        lowercase((char *)str);
        while(str[i] >= 9 && str[i] <= 13 || str[i] == ' ')
            i++;
        if(str[i] == '-')
            sign = -1;
        if(str[i] == '-' || str[i] == '+')
            i++;
        while(str[i] && ((j = ft_strchr(base,str[i])) >= 0))
        {
            res *= str_base;
            res += j;
            i++;
        }
    }
    return (sign * res);
}

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        printf("%d", ft_atoi_base(argv[1],atoi(argv[2])));
    }
    return (0);
}