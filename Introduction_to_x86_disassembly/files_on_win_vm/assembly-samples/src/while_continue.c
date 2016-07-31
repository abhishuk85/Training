#include <stdio.h>

int main(int argc, char* argv[])
{
	int i = 0;

	while (i < 100)
	{
		i++;
		if (i >= 20 && i <= 40)
		{
			continue;
		}

		printf("i: %i\n", i);
	}

	return 0;
}

