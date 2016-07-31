#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int i = 0;

	do
	{
		printf("i: %i\n", i);
		i++;
	}
	while (i < 10);

	return 0;
}
