/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
 */

/**
 * We set a variable i to 8, and then we loop through the octet, dividing it by 2
 * each time, and adding the remainder to the result
 * 
 * @param octet The octet to reverse.
 * 
 * @return the reverse of the bits of the octet.
 */



unsigned char	reverse_bits(unsigned char octet)
{
	int i = 8;
	unsigned char res = 0;

	while (i > 0)		/* Looping through the octet, dividing it by 2 each time, and adding the remainder to the result. */
	{
		res = res * 2 + (octet % 2);	/* Adding the remainder of the octet divided by 2 to the result. */
		octet = octet / 2;
		i--;
	}
	return (res);
}
