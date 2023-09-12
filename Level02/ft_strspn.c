/*
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t ft_strspn(const char *s, const char *accept)
{
	size_t len; //almacenara lo que cumpla las restricciones
	int i; //recorre accept

	while(s[len] != '\0')
	{
		i = 0;
		while(accept[i] && accept[i] != s[len])
			i++;
		if(!accept[i])
			break;
		len++;
	}
	return(len);
}

int main()
{
	char *s1 = "bri";
	char *s2 = "sabrina";

	printf("mia: s1 = %s, s2 = %s, result = %lu\n", s1 , s2 , ft_strspn(s1,s2));
	printf("original : s1 = %s, s2 = %s, result = %lu", s1, s2 , strspn(s1,s2));
	return 0;
}
