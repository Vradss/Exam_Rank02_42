/*
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);
*/

#include <string.h>
#include <stdio.h>

char    *ft_strpbrk(const char *s1, const char *s2)
{
	while(*s1)
	{
		const char *temp = s2; //se crea un puntero que recorra s2
		{
			while(*temp) //creamos el bucle que recorre s2 
			{		
				if(*s1 == *temp)
					return (char *)s1;
				temp++;
			}
		}
		s1++;
	}
	return NULL;
}


int main()
{
	char *s1 = "vradis";
	char *s2 = "sabrina";
	printf("mia : %s\n", ft_strpbrk(s1,s2));
	printf("original : %s", strpbrk(s1,s2));
	return 0;
}
