#include "kernel.h"

int strlen (char *str)
{
	int len = 0;
	while(str[len]!='\0')
	{
		len++;
	}
	return len;
}

void *memset(void *dst, int c, size_t n)
{
	if(n)
	{
		char *d = dst;
		while(n>0)
		{
			*d = c;
			d++;
			n--;
		}
	}
	return dst;
}

void *memcpy (void * dst, const void * src, size_t n)
{
	char *d = dst;
	const char *s = src;

	if(n)
	{
		for(int i = 0; i<n; i++)
		{
			d[i]=s[i];
		}
	}
	return dst;
}
