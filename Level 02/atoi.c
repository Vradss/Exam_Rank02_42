/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/

#include <unistdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
    int i = 0;
    int result = 0;
    int sign = 1;

    while (str[i] == ' ' || str[i] >= 7 && str[i] <= 13)
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (sign * result);
}

int main()
{
    printf("mia: %d\n", ft_atoi("123"));
    printf("original: %d", atoi("123"));

}