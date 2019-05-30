/*
#include <iostream>
#include <stdio.h>

using namespace std;

char * strncpy(char *dest, const char *src, size_t n)
{
	if (dest == NULL || src == NULL || n < 0)
	{
		return NULL;
	}
	char *res = dest;
	while(n--)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return res;

}

int main()
{
	char *src = "hello world";
	char c[10];
	char *res = strncpy(c, src, 7);

	cout << res << endl;

	return 0;
}
*/