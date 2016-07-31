#include <stdio.h>

int main(int argc, char* argv[])
{
	int i, j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 5)
		{
			printf("i: %i, j: %i\n", i, j);
			j++;
		}

		i++;
	}

	/**
	 * NOTE: This is equivalent to:

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("i: %i, j: %i\n", i, j);
		}
	}

	 **/


	return 0;
}
