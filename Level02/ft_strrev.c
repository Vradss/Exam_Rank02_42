/* 
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/

#include <unistd.h>
#include <stdio.h>

size_t ft_strlen(const char *s)
{
	int i = 0;
	while(s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int len = ft_strlen(str);

	int start = 0;
	int end = len - 1;

	while(start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return str;
}

int main()
{
	char s[] = "vradis";
	printf("mia : %s", ft_strrev(s));

}
