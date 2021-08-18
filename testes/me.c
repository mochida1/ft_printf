#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <unistd.h>

char		*ft_strdup(const char *s1);
size_t 		pstr(char *c);
static int	getuintlen(unsigned int n);
char		*ft_uitoa(unsigned int n);
int			ft_strlen(const char *s);

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

	c = 0;
	printf ("0>>>>>> %llu <<<<<<<0\n", (unsigned long long)c);
	printf ("0_%p_0\n", c);
	printf ("**************\n**************\n**************\n");
	c = ft_uitoa(x);
	printf (">>>>>> %llu <<<<<<<\n", (unsigned long long)c);
	printf ("_%p_\n", c);
	printf ("\n******\n");
	y = pstr(c);
	printf ("|%s| \n", c);
	printf ("--%zu--\n" , y);
	free (c);
	return 0;
}

size_t	pstr(char *c)
{
	size_t	i;
	size_t	end;

	i = 0;
	end = ft_strlen(c);
	while (i < end)
	{
		write (1, c, 1);
		c++;
		i++;
	}
	return (i);
}


static int	getuintlen(unsigned int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

/*
** i → index; i
*/
char	*ft_uitoa(unsigned int n)
{
	char	*s;
	int		i;

	i = getuintlen(n);
	s = malloc(i + 1 * (sizeof(char)));
	if (!s)
		return (0);
	s[i--] = '\0';
	while (n >= 10)
	{
		s[i--] = '0' + (n % 10);
		n /= 10;
	}
	s[i] = '0' + (n % 10);
	return (s);
}

char	*ft_strdup(const char *s1)
{
	int		l;
	char	*c;
	int		i;

	i = 0;
	l = ft_strlen(s1) + 1;
	if (!(c = malloc(l * (sizeof(char)))))
		return (0);
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

int		ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
