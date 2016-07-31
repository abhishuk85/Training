#include <stdio.h>

int main(int argc, char* argv[])
{
	int i = 0;

	while (i < 100)
	{
		i++;
		if (i >= 20)
		{
			break;
		}

		printf("i: %i\n", i);
	}

	return 0;
}

