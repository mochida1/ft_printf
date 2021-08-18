#include <stdio.h>
#include <stdarg.h>

char *fkprintf(size_t i)
{

	size_t j;
	char *str;

	j = 0;
	str = malloc (((i * 4) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (j<i*4)
	{
	str[j++] = '|';
	str[j++] = '%';
	str[j++] = 's';
	str[j++] = '|';
	}
	str[i*4] = '\0';
	return (str);

}

char *ap_poop(size_t i, ...)
{
	size_t j;
	va_list ap;

	j = 0;
	va_start(ap, i);
	while (j<i)
	{

	}


}


int main (void)
{
	static size_t i;
	char *str;

	i = 5;
	str = fkprintf(i);

	printf(str, );

	return (0);
}

