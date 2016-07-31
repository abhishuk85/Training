#include <stdio.h>

int main(int argc, char* argv[])
{
	int i;

	i = 0;
	while (i < 10)
	{
		printf("i: %i\n", i);
		i += 2;
	}

	return 0;
}

