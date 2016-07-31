#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int number;

	if (argc < 2)
	{
		printf("Usage: if_or number\n");
		return 1;
	}

	number = atoi(argv[1]);

	if (number >= 30 || number <= -20)
	{
		printf("correct number\n");
	}
	else
	{
		printf("incorrect number\n");
	}

	return 0;
}
