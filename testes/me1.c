#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	gethexlen(unsigned long ln);
char	*ascii_to_hex(char *ret, unsigned int caps);

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


int main (void)
{
	int i;
	char *c;


	i = -1;
	c = ft_uitoa16(i, 1);
	printf("|%s| -->  abcdef \n", c);
	free (c);
	c = NULL;

	return(0);
}
