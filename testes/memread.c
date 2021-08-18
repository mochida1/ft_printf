#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <unistd.h>

size_t	gethexlen(unsigned long ln);
char	*ascii_to_hex(char *ret, unsigned int caps);
char	*ft_uitoa16(unsigned int n, unsigned int caps);

int main(void) {
/*
    printf("CHAR_BIT    :   %d\n", CHAR_BIT);
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("CHAR_MIN    :   %d\n", CHAR_MIN);
    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("INT_MIN     :   %d\n", INT_MIN);
    printf("LONG_MAX    :   %ld\n", (long) LONG_MAX);
    printf("LONG_MIN    :   %ld\n", (long) LONG_MIN);
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
    printf("UINT_MAX    :   %u\n", (unsigned int) UINT_MAX);
    printf("ULONG_MAX   :   %lu\n", (unsigned long) ULONG_MAX);
    printf("USHRT_MAX   :   %d\n", (unsigned short) USHRT_MAX);
*/
	unsigned int x = UINT_MAX;
	printf ("+%X+\n", UINT_MAX);
	printf ("**%u**\n", x);
	size_t y;
	char *c;
	char *aux;
	int i = 0;

	c = 0;
	while (i < 10)
	{
	y =(unsigned long) c;
	printf ("0>>>>>>%llu<<<<<<<0\n", (unsigned long long)c);
	printf ("0______%p______0\n", c);
	aux = ft_uitoa16 (y, 0);
	printf("<<<<<<<%s>>>>>>>\n", aux);
	c++;
	printf ("**************\n");
	i++;
	free(aux);
	}

	aux = 0;
	return 0;
}

char	*ft_uitoa16(unsigned int n, unsigned int caps)
{
	long long	ln;
	char		*ret;

	ln = n;
	n = gethexlen(ln);
	ret = malloc((1 + n) * sizeof(char));
	if (!ret)
		return (0);
	ret[n--] = '\0';
	while (ln)
	{
		ret[n--] = '0' + (ln % 16);
		ln /= 16;
	}
	ret = ascii_to_hex(ret, caps);
	return (ret);
}

size_t	gethexlen(unsigned long ln)
{
	size_t	i;

	i = 0;
	while (ln)
	{
		ln /= 16;
		i++;
	}
	return (i);
}

char	*ascii_to_hex(char *ret, unsigned int caps)
{
	int	i;

	i = 0;
	if (caps)
	{
		while (ret[i])
		{
			if (ret[i] > 57 && ret[i] < 64)
				ret[i] += 7;
			i++;
		}
	}
	else
	{
		while (ret[i])
		{
			if (ret[i] > 57 && ret[i] < 64)
				ret[i] += 39;
			i++;
		}
	}
	return (ret);
}
