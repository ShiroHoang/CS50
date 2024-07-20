#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s[100];
	char a[100];
	gets(s);
	gets(a);
	char* p = strstr(s, a);
	while (p != NULL)
	{
		for (int i = strlen(a) - 1; i >= 0; i--)
		{
			*(p++) = a[i];
		}
		p = strstr(s, a);
	}

	printf("\n%s", s);
}
